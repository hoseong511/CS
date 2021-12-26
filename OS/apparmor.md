## **AppArmor**
- 앱아머는 효과적이고 사용하기 쉬운 Linux 애플리케이션 보안 시스템이다.
<br>

- 올바른 동작을 하는지 감시하고, 알려진 응용 프로그램이나 알려지지 않은 응용 프로그램에 결함이 악용되는 것을 방지하여 내/외부 위협으로 부터 운영체제와 응용 프로그램을 사전에 보호한다.
<br>

- [강제 접근 제어(Mandatory Access Control; MAC)](https://hoseong511.github.io/CS/OS/ac_dac_mac)를 제공하여 기존 Unix 임의 접근 제어(Discretionary Access Control; DAC) 모델을 보완한다.
<br>

- 버전 2.6.36부터 메인 라인 Linux 커널에 포함되었다.
<br>

- 리눅스 침입 탐지 시스템(LIDS)[^LIDS]이다.
<br>

### **설치 확인**
대부분 Linux 배포판(ex. Debian, Ubuntu, OpenSUSE)에 AppArmor가 제공된다.   
<br>

![image](https://user-images.githubusercontent.com/62678380/146114839-4027a971-b8df-46ad-a308-604cf06458c5.png)   
<br>

### **AppArmor 프로필**
- 프로필은 /etc/apparmor.d에 저장됨..
- 프로필은 `complain mode` 또는 `enforce mode`로 실행할 수 있음.
	- `complain mode` : 응용프로그램 실행을 제한하지 않고, 위반 사항을 보고하는 로그만 기록.
	- `enforce mode` : 응용프로그램 실행을 제한함.
- 프로파일 만들기
	```sh
	apt install apparmor-utils
	aa-genprof /path/to/binary
	# 다른 터미널에서 해당 응용 프로그램에서 작동
	# 다른 터미널에서 실행 것들만 허용한다
	aa-complain /path/to/binary
	aa-enforce /path/to/binary
	```   

	즉, 해당 프로그램에서 예기치 못한 실행 명령어들을 제한 할 수 있는 것이다.

<!--[![asciicast](https://asciinema.org/a/4mgQT4ktUyegenHOjG72N9QsU.svg)](https://asciinema.org/a/4mgQT4ktUyegenHOjG72N9QsU)   -->

- 프로파일 만들기 유튜브 - [https://www.youtube.com/watch?v=0t-UZFBNyF0](https://www.youtube.com/watch?v=0t-UZFBNyF0)
	- Example 1   
		```sh
		sudo aa-genprof /home/hossong/sample
		# 원하는 명령어들 실행...
		scan
		# 사용된 명령어들 조회
		write
		save
		```   
		```sh
		sudo vim /etc/apparmor.d/home.hossong/sample

		# Last Modified: Sun Dec 26 11:47:21 2021
		#include <tunables/global>

		/home/hossong/sample {
		#include <abstractions/base>

		/home/hossong/sample mr,
		owner /home/*/test1 w,
		# <이 부분에 허용할 명령어들을 추가할 수 있다>
		}
	- Example 2
		```sh
		aa-logprof #거부 처리된 항목을 조회하고 등록 여부를 진행함.
		aa-disable
		aa-enforce
		```
<br>

- 비활성화하기   
	```sh
	sudo aa-disable [app명]
	#sudo ln -s /etc/apparmor.d/usr.bin.sudo /etc/apparmor.d/disable/
	#sudo apparmor_parser -R /etc/apparmor.d/disable/usr.bin.sudo
	#sudo apparmor_status
	```

<br>

### **AppArmor 로그 메시지 확인**
잠재적으로 유해한 작업을 수행하는 응용 프로그램을 거부할 때마다 이벤트가 기록된다. 시스템에 따라 syslog, auditd, kernel log 또는 journal log에서 볼 수 있다.   
```sh
$ sudo journalctl -fx
```
<br>

### **SELinux와 비교**
- RPM 기반 Red Hat, Fedora, CentOS에서 사용되는 보안 시스템이다.

- SELinux는 프로세스를 제한하는 측면에서 더 안전하지만, 매우 복잡한 정책이 수반된다. SELinux 정책은 가독성과 구성 측면에서 사용자가 접근하기 어렵다.
<br>

### **Reference**
- [https://wiki.apparmor.net/](https://wiki.apparmor.net/)
- [https://archive.md/VbER4](https://archive.md/VbER4)
- apparmor 프로파일 만들기 - [https://nostressdev.tistory.com/5?category=868783](https://nostressdev.tistory.com/5?category=868783)
- apparmor 비활성화 활성화 - [https://www.linuxcapable.com/ko/how-to-enable-disable-apparmor-on-ubuntu-20-04/](https://www.linuxcapable.com/ko/how-to-enable-disable-apparmor-on-ubuntu-20-04/)

[^LIDS]: 리눅스 커널에 강제적 접근 통제(MAC)를 구현함으로써 커널 보안을 강화하는 커널 관련 관리 툴이다. LIDS가 선택된 파일 접근, 모든 시스템 네트워크 관리 동작, 메모리 그리고 입출력 접근 등을 보안 정책에 따라 제한한다. 심지어 루트 계정도 보안 정책에 의거 접근이 불가능 할 수 있다.