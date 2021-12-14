## coredump를 이용하여 Linux kernel panic 대응하기
구동 중인 OS가 갑자기 kernel panic등으로 crash되었을 때, coredump를 이용하면 crash되었을 때, memory를 file로 dump할 수 있다. system log 등에 아무런 기록이 없을 때, coredump 파일은 문제 원인을 파악하는데 도움됨.

### kernel crash의 원인
- crash는 kernel이 스스로 제어/복구 할 수 없는 상황이 되었을 때, 발생함.
- kernel이 error를 감지했을 때, Linux의 경우 kernel panic이 되고, hang/reboot 되는것
- RAM 불량 : 메모리가 물리적으로 불량인 경우
- 그 밖의 장치 문제 : 하드웨어 관련된 문제. 물리적인 불량일 경우도 있지만, 하드웨어를 지어하는 firmware/driver의 문제일 수 도 있다.
- 소프트웨어 이슈 : kernel이나 그 Module, 혹은 특정 process의 버그(문제)일 수도 있다.

### kdump-tools
- kdump-tools은 Linux kernel의 kdump를 관리함.
- kdump-tools에는 kexec-tools[^kexec-tools], makedumpfiles이 dependacy로 되어있고, 기존의 kexec-tools로 설정하는것보다 손쉽게 설정이 가능함.
- 원리는    
Linux kernel panic 발생 -> 디스크 메모리 dump화 -> 새로운 커널로 재부팅 -> dump파일로 원인 분석

### kdump-tools 설치, 설정
- `sudo apt-get install kdump-tools`
	- kexec-tools 재부팅 옵션 : yes -> 새로운 커널로 재부팅 할건지?
	- kdump-tools 항상사용 여부 옵션 : yes
- 설치가 완료된 후 재부팅을 해주어야 kexec-tools과 kdump-tools 이 사용가능해진다.   
[![asciicast](https://asciinema.org/a/V9CU5mSfCrQDMYnd2SH0uLlMw.svg)](https://asciinema.org/a/V9CU5mSfCrQDMYnd2SH0uLlMw)  
<!-- - kdump가 작동되기 위한 몇 가지 설정.
	- crashkernel: kernel panic으로 현재 시스템이 종료될 시, 새로운 커널(crashkernel)로 부팅되게 하는 옵션. 메모리를 지정해준다(ex. crashkernel=384M-:128M)
	- kexec_crash_loaded : 1로 세팅 -->
	
- 재부팅 후, crashkernel 확인
	```sh
	su -  
	cat /proc/cmdline # crashkernel 메모리 사이즈 확인
	vi /etc/default/kexec # USE_GRUB_CONFIG=true 로 변경
	vi /etc/default/grub.d/kexec-tools.cfg # 추가적으로 필요하면 여기서 crarshkernel 메모리 사이즈 설정
	update-grub # 바꾼 설정 업데이트
	reboot
	kdump-config show # ready to kdump 확인
	```
- 강제 kernel panic 
	```sh
	cat /proc/sys/kernel/sysrq # 0이 아닌지 확인, 0이면 sudo sysctl -w kernel.sysrq=1
	echo c > /proc/sysrq-trigger
	```   
	- 재부팅 된 후, `ls /var/crash` 확인 -> 날짜로된 디렉토리가 생성된 것을 확인
		

### TruobleShooting
- 리부팅이 안된다.. 왜인지 알수가 없다. 
	why didn't work kdump on virtual box...   
-> [https://bugzilla.redhat.com/show_bug.cgi?id=1028397](https://bugzilla.redhat.com/show_bug.cgi?id=1028397)
- 
- 암호화된 LVM이어서 덤프를 만들 수가 없는 것.
- 암호화된 LVM을 제외하고는 가능!

### **Reference**
- [https://www.redhat.com/sysadmin/linux-kernel-panic](https://www.redhat.com/sysadmin/linux-kernel-panic)
- [https://superuser.com/questions/280767/how-can-i-enable-kernel-crash-dumps-in-debian](https://superuser.com/questions/280767/how-can-i-enable-kernel-crash-dumps-in-debian)
- [http://www.iorchard.net/2016/11/01/using_crashdump_for_troubleshooting_kernel_crash.html](http://www.iorchard.net/2016/11/01/using_crashdump_for_troubleshooting_kernel_crash.html)
- [http://shareithw.blogspot.com/2017/05/ubuntu-kdump-ppc64le.html](http://shareithw.blogspot.com/2017/05/ubuntu-kdump-ppc64le.html)



[^kexec-tools]: 현재 커널에서 BIOS, 부트로더 등을 거치지 않고 새로운 커널로 부팅 할 수 있다. 이는 crash dump에서 kernel crash가 발생했을 경우 kexec를 이용하여 새로운 커널(second kernel, capture kernel)로 부팅을 하게 되고, 메모리를 dump하는것   
