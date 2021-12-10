## How to install debian on virtual box
1. LVM을 사용하기 -> LVM을 설정하는 방법
2. KDump와 AppArmor 실행하기
3. ssh 서비스의 포트는 4242, root 접속은 금지 -> 
4. 새로운 유저를 추가하기
5. UFW 방화벽을 설정하고 포트는 4242만 열어두기
6. 방화벽을 설치하기 위해서는 DNF가 필요할것이다.
7. hostname 설정하기
8. sudo를 설치하고 사용가능하게 설정하기
9. 언어 설정 바꿔보기 (`dpkg-reconfigure locales`), 한글로 설치를 했더니 중간중간 깨지는 부분이 있다.

- sshd 및 현재 시스템 내에서 열린 포트를 확인할 수 있다  lsof -i
	- root 접속 x :   
		`#PermitRootLogin prohibit-password`  
		- 기본값이 root 접속 불가
		- yes이면 root 접속
	- 비밀번호 접속 설정 : 
		`#PasswordAuthentication yes`   
		- 기본값이 비밀번호 접속   
		- no이면 비밀키 접속
	- `/etc/ssh/sshd_config` 를 확인하면
		`#AuthorizedKeysFile	.ssh/authorized_keys .ssh/authorized_keys2`
		- 기본값이 authorized_keys, authorized_keys2
		- id_rsa.pub을 해당 기본값의 이름으로 바꾸기
		- 비밀키 갖고 ssh 접속 가능

	
- hostname 변경하기
	- `hostname [이름]` 일시적으로 변경
	- `hostnamectl set-hostname --static [이름]` 영구적으로 변경
	- `shutdown -r now` or `reboot` 시스템을 재시작해야 hostname이 변경
- su vs su - : su - 는 su -l, su --login 과 같은 명령어다, 로그인해서 접속한 계정의 환경변수를 가져온다. root계정에 환경변수를 하나 등록하고 su로 접속해서 해당 환경변수가 조회되는지 확인하기(env)
- 그룹 만들고 해당 그룹에 유저를 추가해보기 
	- `groupadd [이름]`
	- `groupdel [이름]`
	- `gpasswd -a [user명] [group명]`
	- `gpasswd -d [user명] [group명]`
		- `/etc/sudoers` 를 확인해보면    
		```sh
			# Allow members of group sudo to execute any command
			%sudo	ALL=(ALL:ALL) ALL
		```
		- 해당 그룹에 소속되면 sudo 권한을 갖는 것.
		- 유저에게만 sudo 권한을 주고 싶으면 root 아래에 추가  
		```sh
			# User privilege specification
			root	ALL=(ALL:ALL) ALL
		```

- 
- kdump is a feature of the Linux kernel that creates crash dumps in the event of a kernel crash. [link](https://www.thegeekstuff.com/2014/05/kdump/)
- LVM(Logical Volume manageer)은 Logical Volume을 효율적이고 유연하게 관리하기 위한 커널의 한 부분이자 프로그램이다.
	- 디스크나 대용량 스토리지 장치를 유연하고 확장이 가능하게 다룰 수 있는 기술이며 이를 커널에 구현한 기능이다.
	- 전통적으로 저장 장치를 사용했던 방식은 물리 디스크를 파티션이라는 단위로 나누어서 이를 OS에 마운트하여 사용했는데, 마운트를 하려면 파티션을 특정 디렉토리와 일치시켜 주어야 했다, 만약 특정 파티션에 마운트된 파티션이 용량이 일정 수준 이상 찼을 경우 일련의 번거로운 작업을 수행해야 했다.
		- 추가 디스크를 장착
		- 추가된 디스크에 파티션 생성 및 포맷
		- 새로운 마운트 포인트(/home2)를 만들고 추가한 파티션을 마운트
		- 기존 home 데이터를 home2에 복사 또는 이동
		- 기존 home 파티션을 언마운트
		- home2를 home으로 마운트
	- LVM은 파티션 대신 볼륨이라는 단위로 저장 장치를 다룰 수 있으며, 물리 디스크를 볼륨 그룹으로 묶고 이것을 논리 볼륨으로 분할하여 관리한다.
- GRUB(Grand Unified Bootloader)는 GNU하에서 개발된 멀티부트로더이다. 부트로더란 리눅스가 부팅되기까지 부팅의 전과정을 진행하는 부팅전문프로그램을 의미한다.