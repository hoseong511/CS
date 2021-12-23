## How to install debian on virtual box
1. 맥, 윈도우, 리눅스 OS들에 대해서, 클러스터는 왜 맥을 사용할까?

1. 가상화는 뭘까?, 가상화를 하는 이유는 뭘까?, 버추얼박스를 사용하는 이유는?
	- [virtual](https://hoseong511.github.io/CS/OS/virtual) 완료
	<br>

1. 리눅스 배포판 중 데비안, 레드햇, 센토스, 우분투, 페도라 각 특징은?
	- [debian](https://hoseong511.github.io/CS/OS/debian) 완료
	<br>

1. 데비안 설치방법?
	- [How to install](https://hoseong511.github.io/CS/OS/howto) 완료
	<br>

1. LVM?, 암호화된 LVM된 파티션을 만드는 방법은?, LVM을 사용하기 -> LVM을 설정하는 방법?
	- [LVM?](https://hoseong511.github.io/CS/OS/lvm) 완료
	<br>

	- LV 추가하는 시나리오
	<br>

	- LV 문제 해결 
	<br>

	- SWAP : 디스크내에 존재하는 가상적인 메모리 공간, 물리적인 메모리(RAM) 연장 공간처럼 쓰이는 공간을 스왑이라고 한다. 하드 디스크의 일부를 RAM처럼 사용할 수 있게 만드는 것
	<br>

1. KDump? AppArmor? SELinux?, 설정하는 법?
	- kdump는 활성화는 됨. 커널 패닉 시, dump 파일을 만들고 재부팅되는 과정 확인이 안되는 상황 [coredump?](https://ko.wikipedia.org/wiki/%EC%BD%94%EC%96%B4_%EB%8D%A4%ED%94%84)
	<br>
	
	- kdump 재부팅 안되는 원인 파악 완료 [kdump 정리](https://hoseong511.github.io/CS/OS/kdump)
	<br>

	- [AppArmor](https://hoseong511.github.io/CS/OS/apparmor) 완료
	<br>

1. 리눅스 배포판 별로 apt-get, apt, aptitude, yum, rpm, dpkg, ... 들이 뭘까?
	- apt(Advanced Packaging Tool)는 데비안 GNU/리눅스 계열의 패키지 관리 명령도구로 우분투에서도 지원 
		- apt-get : 인증된 소스에서 패키지 및 패키지에 대한 정보를 검색하고 종속성과 함께 패키지를 설치, 업그레이드 및 제거. 오래전부터 사용되어와서 안정적이고 호환성이 높다는 장점.
		<br>

		- apt(Adbanced Packaging Tool) : apt-get와 내부 동작의 차이는 거의 없다. apt에서는 apt-get에서 자주 사용하는 옵션들을 추출해서 사용자들이 사용하고 보기 편하게 만듦. 추가적인 정보를 제공! [참조](https://askubuntu.com/questions/445384/what-is-the-difference-between-apt-and-apt-get)   
		<br>
		![image](https://user-images.githubusercontent.com/62678380/146123335-e995fdc6-4bea-40bc-bcfb-7a4675f0892f.png)
		<br>

		- aptitude : apt의 프론트엔드 프로그램이다. 소프트웨어 패키지의 목록을 보여주고, 사용자가 패키지를 능동적으로 설치 혹은 삭제하도록 허용함. 
			```sh
			$ apt install aptitude
			$ aptitude
			```   
			![image](https://user-images.githubusercontent.com/62678380/146129975-03b1cbc3-0001-4b5d-9027-cef320985a11.png)
	<br>

1. ssh?, ssh 설정?, public-private key?, 암호화 알고리즘으로 키를 생성, ssh client이용,
	- [ssh 정리](https://hoseong511.github.io/CS/OS/ssh) 완료
	<br>

1. 유저를 추가하는 명령어, sudo를 줄 수 있는 방법들?, 
	- 그룹으로 지정하기 -> sudo 그룹에 포함시키면 끝.
	<br>

	- 유저하나만 지정하기 -> `visudo`로 설정해주기, `etc/sudoers`에서 수정하기.
	<br>

	- [https://unix.stackexchange.com/questions/476416/adding-a-user-to-sudo-group-vs-creating-a-sudoers-file](https://unix.stackexchange.com/questions/476416/adding-a-user-to-sudo-group-vs-creating-a-sudoers-file)
	<br>

1. 방화벽?, UFW 방화벽을 설정하고 포트는 4242만 열어두기, DNF?
	- [ufw](https://hoseong511.github.io/CS/OS/firewall) 완료
	<br>

1. hostname 설정하는 방법들?
	- 완료   
	![image](https://user-images.githubusercontent.com/62678380/145750745-f54a4653-ec87-46f5-a814-4f34673a9f35.png)
	<br>

1. 인트라아이디를 유저명으로 하는 유저 생성, sudo와 user42 그룹에 포함
	- 완료   
	![image](https://user-images.githubusercontent.com/62678380/145750818-be7de8a0-ae0b-4949-8175-8892fdec07e9.png)


1. 강력한 비밀번호 정책사용하기
	- 현재 비밀번호는 30일 마다 소멸 -> PASS_MAX_DAYS
	- 변경을 위해 기다려야 하는 기간은 최소 이틀로 설정 -> PASS_MIN_DAYS, 0으로 하면 변경한 후 바로 또 변경이 가능하다
	- 비밀번호 소멸 7일 전에 경고 메시지 -> PASS_WARN_AGE
	- 비밀번호는 최소 10글자 이상, 대문자와 숫자를 포함, 같은 글자 3번 이상 연속되면 안됨, 유저명 포함x
	- 이전 비밀번호에 포함되지 않는 문자 최소 7개 이상
	- 루트 권한 비밀번호 또한 해당 규칙을 따라야 함.
	- [https://nostressdev.tistory.com/9](https://nostressdev.tistory.com/9)
	- `/etc/login.defs`에 비밀번호 관련 날짜를 설정할 수 있다. 다만 현재 존재하는 계정들에는 `chage`명령어로 바꿔주어야 한다.
	- `passwd`으로 비번 변경.   
		```
		qwer1234QWER
		qwer1DF56789
		qwer1234QWER
		````
	<br>
	- 모듈 `pam_cracklib`에 대해서 자세히 보기 - [https://linux.die.net/man/8/pam_cracklib](https://linux.die.net/man/8/pam_cracklib)   


1. sudo? sudo strict rules? 
	- sudo 인증 시, 비밀번호가 틀렸을 때 3번의 기회만 주어짐
	- sudo 권한 사용 중, 비밀번호가 틀렸을 때 설정한 오류 메시지가 출력
	- sudo 권한을 이용하여 수행한 명령어들 입출력 모두 기록되어야 함. log 파일로 `/var/log/sudo/` 폴더에 저장되어야함.
	- tty?, tty 모드는 활성화
		- tty에 대해서 좀 더 공부가 필요!!
	- sudo 권한으로 이용할 수 있는 폴더 경로는 반드시 제한
		- secure_path를 설정하는 이유 [link](https://www.tuwlab.com/ece/24044)
	- [https://ko.linux-console.net/?p=1985](https://ko.linux-console.net/?p=1985)
	```sh
	Defaults        secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin" #sudo 실행 시 만들어진 샌드박스 안에서 실행하게 하는 기능. 트로이목마 같이 path설정을 바꿔버리는 악성코드에 대해 예방이 가능하다. 즉, path를 바꾸는 코드가 심어진다면 실존하지 않는 샌드박스 경로에 심어져서 예방이 가능해진다는 말이다.
	Defaults        passprompt="비밀번호를 묻는다"
	Defaults        badpass_message="비밀번호 틀림 다시 시도!"
	Defaults        requiretty
	Defaults        log_input, log_output
	Defaults        iolog_dir="/var/log/sudo"
	Defaults        passwd_tries=3
	```
	<br>

1. bash 환경에서 작동되는 monitoring.sh를 작성
	- cron? 10분 마다 작동되고 오류 발생 처리하기
	- 운영체제의 아키텍쳐와 커널 버전 `uname -a`
	- 물리 프로세서의 개수 `lscpu | grep ^CPU\( | awk '{print $2}'`
	- 가상 프로세서의 개수 `lscpu | egrep "^Thread|^Core|^Socket" | awk -v mul=1 '{mul*=$2;} END {print mul}' FS=":"`
	- 서버 내에서 사용가능한 램 가동률을 백분율로 표시 `free --mega | grep Mem | awk '{ printf "%d/%dMB (%.2f%%)\n", $3, $2, ($3/$2 * 100.0) }'`
	- 서버 내에서 사용가능한 메모리 가동률을 백분율로 표시 `df -t ext4 -BM --total | grep total | awk '{printf "%d/%dGb (%.2f%%)\n", $3, $4/1000, $5}'`
	- 현재 프로세서 가동률을 백분율로 표시 `top -bn1 | grep Cpu | awk '{ print (100-$4) "%"}' FS=','`
	- 마지막 부팅 시간과 날짜 `who -b | awk '{print $3, $4}'`
	- LVM이 활성화 되었는지 여부 `lsblk | grep -c lvm | awk '{if ($1 > 0) print "yes"; else print "no"}'`
	- 활성화된 연결 수 `ss | grep -c tcp | awk '{print $1 " ESTABLISHED"}'`
	- 서버를 사용하고 있는 유저 수 `users | wc -w`
	- 서버의 IPv4 주소와 MAC (Media Access Control = 매체 접근 제어) 주소 `ip addr | grep link/ether | awk -v "ip=$(hostname -I)" '{printf "IP %s (%s)\n", ip, $2}'`
	- sudo로 실행된 커맨드의 수 `grep sudo /var/log/auth.log | grep -c COMMAND= | awk '{print $1 cmd}'` 
	<br>

9. 언어 설정 바꿔보기 (`dpkg-reconfigure locales`), 한글로 설치를 했더니 중간중간 깨지는 부분이 있다.

- sshd 및 현재 시스템 내에서 열린 포트를 확인할 수 있다  lsof -i
	- root 접속 x :   
		`#PermitRootLogin no` , prohibit-password은 비밀키로 접근은 가능 
		- 기본값이 root 비밀번호 접속 불가
		- no이면 비밀키, 비밀번호 접속 불가
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
		- static 옵션 붙이면 이름에 대문자 사용이 가능해짐
	- `shutdown -r now` or `reboot` 시스템을 재시작해야 hostname이 변경
	![image](https://user-images.githubusercontent.com/62678380/145750098-5c9b7e8a-452c-4e9b-8454-fb0bd473e584.png)   
	- sudo로 실행 시 위와 같은 오류 발생.
	- `/etc/hosts`에 적혀있는 hostname이 달라서 발생하는 것   
	![image](https://user-images.githubusercontent.com/62678380/145750317-8ed9e132-f2f2-4d01-9d39-aa28b253445e.png)
- su vs su - : su - 는 su -l, su --login 과 같은 명령어다, 로그인해서 접속한 계정의 환경변수를 가져온다. root계정에 환경변수를 하나 등록하고 su로 접속해서 해당 환경변수가 조회되는지 확인하기(env)
	![image](https://user-images.githubusercontent.com/62678380/145932616-2fbf081c-9956-433e-b1bc-90909160a939.png)
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

- `select-editor` : 에디터 변경하는 명령어.
- cron으로 wall을 실행하면 somewhere! -> tty1에서 wall 하면 위치 확인 가능 **todo: cron 시나리오 정리**
- crontab -l, crontab -e
- tail -f cat /var/log/syslog | grep CRON
- `bash /hossong/hi.sh 1>> /home/hossong/excute.log 2>> /home/hossong/fail.log` 2는 표준 에러 의미, 1는 표준 출력 (&를 붙여주어야 1을 표준 출력으로 인식) 
	- 표준 출력 의미인 1이 생략되어있음.
	- 위와 같이 하면 정상이면 excute.log에 기록되고, 에러면 fail.log에 기록됨.
	- `bash /hossong/hi.sh 1 > /dev/null 2>&1` : >&1은 표준출력으로 리다이렉션함. 즉, 이렇게 사용하면 에러에 대한 처리도 됨. 앰퍼샌드(&) + 숫자는 파일디스크립터를 의미하게 만듦.
	- 그렇다면 '왜 &2>&1 로 사용하지 않는거지?'에 대한 답변 [링크](https://stackoverflow.com/questions/818255/in-the-shell-what-does-21-mean). `command & 까지 인식 그리고 2>&1`
	- ``
	- [참고](https://blogger.pe.kr/369)

- us, user : time running un-niced user processes 사용자 영역에서 사용한 cpu 시간
- sy, system : time running kernel processes system 영역에서 사용된 cpu 시간
- ni, nice : time running niced user processes 프로세스 우선순위 따라 사용된 cpu 시간
- wa, IO-wait : 다른 통신으로 인해 cpu 작업이 일시적으로 대기하는데 소비된 cpu 시간
- hi : 
- si
- st
- sudo su 막기 - [https://forum.ubuntu-kr.org/viewtopic.php?t=27631](https://forum.ubuntu-kr.org/viewtopic.php?t=27631)
## 설치 화면에서 파티션, LV 만들기

## lighttpd, mariadb, php, wordpress
- [https://www.atlantic.net/dedicated-server-hosting/how-to-install-wordpress-with-lighttpd-web-server-on-ubuntu-20-04/](https://www.atlantic.net/dedicated-server-hosting/how-to-install-wordpress-with-lighttpd-web-server-on-ubuntu-20-04/)
여기 실패
- how to install lighttpd - [https://www.osradar.com/install-lighttpd-debian-10/](https://www.osradar.com/install-lighttpd-debian-10/) 여기 잘됨!

- how to install wordpress - [https://www.osradar.com/install-wordpress-with-lighttpd-debian-10/](https://www.osradar.com/install-wordpress-with-lighttpd-debian-10/)

- mariadb랑 mysql이랑 같음 -> apt install mariadb-server
- root 디렉토리 바꾸기 `server.document-root = "여기에 수정"`

## jenkins
- install - [https://www.jenkins.io/doc/book/installing/linux/#debianubuntu](https://www.jenkins.io/doc/book/installing/linux/#debianubuntu)
- 


## haproxy 로드 밸런싱 기능 이용
- L4, L7 과 같은 하드웨어 로드밸런스를 대체하기 위한 오픈소스 소프트웨어. 

- nginx와 다른 점은 1. 웹서버 없이 오직 로드밸런싱 기능만 2. 특정 API에 접근하여 서버 상태 점검하는 헬스 체크 기능 보유

- haproxy 한글 설명 - [https://leffept.tistory.com/309](https://leffept.tistory.com/309)

- haproxy 사용법 - [https://techexpert.tips/ko/%ED%95%98%ED%94%84%EB%A1%9D%EC%8B%9C/%EC%9A%B0%EB%B6%84%ED%88%AC-%EB%A6%AC%EB%88%85%EC%8A%A4%EC%97%90-haproxy-%EC%84%A4%EC%B9%98/](https://techexpert.tips/ko/%ED%95%98%ED%94%84%EB%A1%9D%EC%8B%9C/%EC%9A%B0%EB%B6%84%ED%88%AC-%EB%A6%AC%EB%88%85%EC%8A%A4%EC%97%90-haproxy-%EC%84%A4%EC%B9%98/)

- haproxy vs nginx 비교 블로그(한글) - [https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=hanajava&logNo=221677116693](https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=hanajava&logNo=221677116693)

- haproxy vs nginx 비교 stackoverflow - [https://stackoverflow.com/questions/21173496/haproxy-vs-nginx#:~:text=haproxy%20is%20a%20%22load%20balancer,server%20then%20haproxy%20is%20enough.](https://stackoverflow.com/questions/21173496/haproxy-vs-nginx#:~:text=haproxy%20is%20a%20%22load%20balancer,server%20then%20haproxy%20is%20enough.)

- revese proxy ? - [https://today-hello.tistory.com/109](https://today-hello.tistory.com/109)
	- 쉽게 말해 서버를 대신하는 녀석을 리버스 프록시, 클라이언트(일반유저)를 대신하는 녀석을 프록시

## python flask
- flask - [https://wings2pc.tistory.com/entry/%EC%9B%B9-%EC%95%B1%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D-%ED%8C%8C%EC%9D%B4%EC%8D%AC-%ED%94%8C%EB%9D%BC%EC%8A%A4%ED%81%ACPython-Flask-%EC%84%A4%EC%B9%98-%EB%B0%8F-%EC%9B%B9-%EC%95%A0%ED%94%8C%EB%A6%AC%EC%BC%80%EC%9D%B4%EC%85%98Web-Application-%EC%8B%9C%EC%9E%91](https://wings2pc.tistory.com/entry/%EC%9B%B9-%EC%95%B1%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D-%ED%8C%8C%EC%9D%B4%EC%8D%AC-%ED%94%8C%EB%9D%BC%EC%8A%A4%ED%81%ACPython-Flask-%EC%84%A4%EC%B9%98-%EB%B0%8F-%EC%9B%B9-%EC%95%A0%ED%94%8C%EB%A6%AC%EC%BC%80%EC%9D%B4%EC%85%98Web-Application-%EC%8B%9C%EC%9E%91)
	- python3 app.py로 실행을 해야 `app.run(host='')` 부분이 실행된다.
	- 
- nohup flask !! - [https://imsoncod.tistory.com/17](https://imsoncod.tistory.com/17)


## Virtual Box - cpu
- CPU Hot-plugging 
	- `VBoxManage modifyvm VM-name --cpuhotplug on` hotplug 기능이 켜져야 이용가능하다.
	- `VBoxManage modifyvm born6_service --plugcpu 1`
	- `VBoxManage modifyvm born6_service --unplugcpu 1` 숫자는 cpu의 아이디 
	- `echo 1 > /sys/devices/system/cpu/cpu1/online` cpu1 켜기
- VM virtualBox - [https://docs.oracle.com/en/virtualization/virtualbox/6.0/admin/cpuhotplug.html](https://docs.oracle.com/en/virtualization/virtualbox/6.0/admin/cpuhotplug.html)

- how to get the number of vCPUs - [https://www.thegeekdiary.com/how-to-get-the-number-of-vcpus-that-oracle-vm-guest-can-get-in-oracle-vm/](https://www.thegeekdiary.com/how-to-get-the-number-of-vcpus-that-oracle-vm-guest-can-get-in-oracle-vm/)

- df - [http://blog.imm.cnr.it/content/linux-check-disk-space-command-view-system-disk-usage-df-and-du](http://blog.imm.cnr.it/content/linux-check-disk-space-command-view-system-disk-usage-df-and-du)