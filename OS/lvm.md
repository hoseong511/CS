## **논리볼륨관리자 LVM(Logical Volume Manager)**
LVM은 디스크공간을 자유롭게 추가하고 줄일 수 있게 만들어준다.   
만약 파일 시스템에 추가적인 공간이 필요하다면, 새로 추가한 디스크 공간을 기존 LV(Logical Volume)에 확장시킬 수 있다.

### **LVM**

- 물리볼륨(Physical Volume) : 일반적으로 하드디스크 파티션이나 RAID 장치와 같이 하드디스크 파티션과 비슷하게 보이는 장치를 지칭함.

- 논리볼륨(Logical Volume) : 여러 물리볼륨이 논리볼륨을 이룸. LVM에서 논리볼륨은 LVM을 사용하지 않는 시스템의 하드디스크 파티션과 유사함.

- 볼륨그룹(Volume Group) : 논리볼륨이 모여서 볼륨그룹을 이룸. LVM에서 볼륨그룹은 LVM을 사용하지 않는 시스템의 물리적 하드디스크와 유사함.

	![lvm](https://www.tecmint.com/wp-content/uploads/2014/07/Create-Logical-Volume-Storage.jpg)   

	LVM은 파티션과 하드디스크에 비해 저장 공간을 높은 차원에서 보게 한다.   

<br>

### **LVM 명령어**
- 생성
	- pvcreate
	- vgcreate
	- lvcreate
- 조회
	- pvdisplay
	- vgdisplay
	- lvdisplay
- 추가 / 변경
	- vgextend, lvextend
	- vgreduce (그룹 내에 멤버 제거)
- 제거
	- pvremove
	- vgremove
	- lvremove

<br>

### **기존 LV에 용량추가하기**
기존에 사용중이던 lvm 타입의 저장소가 가득 찼을 경우, 새롭게 추가한 저장소를 기존 LV 저장소에 연결하고 싶을 때   
[![asciicast](https://asciinema.org/a/J0T38ADtzxKHwpJ6R3Wz4ex33.svg)](https://asciinema.org/a/J0T38ADtzxKHwpJ6R3Wz4ex33)   
- `fdisk -l`로 확인해보면 기존 저장소에 용량이 늘었음을 확인할 수 있다.
- 이것은 따로 마운트를 하는 과정이 아니라 그런지.. 파일시스템 테이블(/etc/fstab)에 적어주지 않아도 된다.

<br>

### **버추얼 박스에서 저장소 추가하기**
- 디스크 모양 버튼 클릭   
	![image](https://user-images.githubusercontent.com/62678380/145933522-02c83474-f583-4233-87af-6efc689c0a4c.png)
- 새 디스크 만들기   
	![image](https://user-images.githubusercontent.com/62678380/145933571-7eba7226-1428-45d8-8032-9b6ba342df13.png)
- 설정하기1   
	![image](https://user-images.githubusercontent.com/62678380/145933920-b7f1ca77-5385-4711-afbc-dd31fcf68e3c.png)
- 설정하기2   
	![image](https://user-images.githubusercontent.com/62678380/145933748-de1b91c8-0ce1-4280-a8a5-7d7636820415.png)
- 설정하기3   
	![image](https://user-images.githubusercontent.com/62678380/145933780-746c50bc-964c-41d3-8cf3-ea1cc8f9e314.png)

- 저장소 추가 완료   
	![image](https://user-images.githubusercontent.com/62678380/145934037-6481c5e1-8d6b-4dc2-b10f-997433b62341.png)

- 확인 `lsblk`   
	![image](https://user-images.githubusercontent.com/62678380/145934189-8732484e-fe26-42d3-baf1-c4916304d479.png)

- 저장소 마운트하기
	- 파티션 -> 파일시스템 포맷 -> 마운트   

	[![asciicast](https://asciinema.org/a/893GfUvLCTdDec0hSg230L6wk.svg)](https://asciinema.org/a/893GfUvLCTdDec0hSg230L6wk)   

	- `vim /etc/fstab`에 저장소를 등록해주어야 재부팅이 되어도 저장소가 마운트되어있다.   
	```sh
	# <file system> <mount point>   <type>  <options>       <dump>  <pass>
	/dev/sdb        /sdb1   ext4    defaults        1       2
	```   

### **Trouble**
- OS를 설치하면서 만들었던 암호화된 LVM 디스크를 지우고, 재부팅 했더니 디스크 찾을 수 없는 문제 발생
	- 부트설정에서 새로운 파티션으로 바꿔주는 설정이 필요
	
- 파일시스템 테이블(fstab)
	- 마운트를 해제한 후 `/etc/fstab`에 남겨둔 다면 아래와 같은 상황이 일어난다  
		![image](https://user-images.githubusercontent.com/62678380/145949703-a253d356-5896-494b-bd90-774d66a2fb37.png)
	- `journalctl -xb` 로 확인해보라고 해서 확인했다.
		![image](https://user-images.githubusercontent.com/62678380/145950070-96a6c4e5-b52f-426e-ba70-e36f2e965c44.png)
	- 대충 `/dev/sdb`를 읽을 수 없다는 내용 같다.
	- 그래서 `/etc/fstab`에 `/dev/sdb`를 지워주었더니 해결됨.
- 기존 남아있는 저장소 제거하기   
	```sh
	# Couldn't find device with uuid vtrmwV-izfm-Canq-Pd7M-Bact-YFqN-1kmSXW.
	# Couldn't find device with uuid 6sFGe5-REzR-lAzz-brPE-meW5-XzHp-2ypmsL.
	```   
	-> `vgreduce --removemissing [vg]`

### **Reference**
- [http://coffeenix.net/doc/lg/issue84/vinayak.html](http://coffeenix.net/doc/lg/issue84/vinayak.html)
- [https://www.tecmint.com/create-lvm-storage-in-linux/](https://www.tecmint.com/create-lvm-storage-in-linux/)
- LVM 명령어 (PV, VG, LV) [link](https://closed0402.tistory.com/103)
- LVM 확장/용량 추가 [link](https://www.juntoday.com/375)
- swap 및 lvm 생성/확장/제거 시나리오 [link](https://doctorlinux.tistory.com/12)