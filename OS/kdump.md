# coredump를 이용하여 kernel crash 대음하기
구동 중인 OS가 갑자기 kernel panic등으로 crash되었을 때, kdump를 이용하면 crash되었을 때, memory를 file로 dump할 수 있다. system log 등에 아무런 기록이 없을 때, kdump 파일은 문제 원인을 파악하는데 도움됨.

### kernel crash의 원인
- crash는 kernel이 스스로 제어/복구 할 수 없는 상황이 되었을 때, 발생함.
- kernel이 error를 감지했을 때, Linux의 경우 kernel panic이 되고, hang/reboot 되는것
- RAM 불량 : 메모리가 물리적으로 불량인 경우
- 그 밖의 장치 문제 : 하드웨어 관련된 문제. 물리적인 불량일 경우도 있지만, 하드웨어를 지어하는 firmware/driver의 문제일 수 도 있다.
- 소프트웨어 이슈 : kernel이나 그 Module, 혹은 특정 process의 버그(문제)일 수도 있다.

### kdump-tools
- kdump-tools를 설치하면 kexec-tools, makedumpfiles이 dependacy로 되어있다.
- kexec-tools
	- 현재 커널에서 BIOS, 부트로더 등을 거치지 않고 새로운 커널로 부팅 할 수 있다. 이는 crash dump에서 kernel crash가 발생했을 경우 kexec를 이용하여 새로운 커널(second kernel, capture kernel)로 부팅을 하게 되고, 메모리를 dump하는것   
	- 리부팅이 안된다.. 왜인지 알수가 없다. why didn't work kdump on virtual box
[![asciicast](https://asciinema.org/a/V9CU5mSfCrQDMYnd2SH0uLlMw.svg)](https://asciinema.org/a/V9CU5mSfCrQDMYnd2SH0uLlMw)

### **Reference**
- [https://superuser.com/questions/280767/how-can-i-enable-kernel-crash-dumps-in-debian](https://superuser.com/questions/280767/how-can-i-enable-kernel-crash-dumps-in-debian)
- [http://www.iorchard.net/2016/11/01/using_crashdump_for_troubleshooting_kernel_crash.html](http://www.iorchard.net/2016/11/01/using_crashdump_for_troubleshooting_kernel_crash.html)