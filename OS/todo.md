## How to install debian on virtual box
1. 맥, 윈도우, 리눅스 OS들에 대해서, 클러스터는 왜 맥을 사용할까?
1. 가상화는 뭘까?, 가상화를 하는 이유는 뭘까?, 버추얼박스를 사용하는 이유는?
1. 리눅스 배포판 중 데비안, 레드햇, 센토스, 우분투, 페도라 각 특징은?
1. 데비안 설치방법?
1. LVM?, 암호화된 LVM된 파티션을 만드는 방법은?, LVM을 사용하기 -> LVM을 설정하는 방법?
1. KDump? AppArmor? SELinux?, 설정하는 법?
1. 리눅스 배포판 별로 apt-get, aptitude, yum, rpm, dpkg, ... 들이 뭘까?
1. ssh?, ssh 설정?, public-private key?, 암호화 알고리즘으로 키를 생성, ssh client이용,
	- [ssh 정리](https://hoseong511.github.io/CS/OS/ssh) 완료
	- scp 사용 해보기   
		ssh의 포트는 -p, scp의 포트는 -P 대/소문자 구별!!   
		```sh
		scp -i [identity file] -P [port] [target file]
 [user@][host]:[path]
		# OR scp -i [identity file] [target file] scp:// [user@][host][:port][/path]
		```
1. 유저를 추가하는 명령어, sudo를 줄 수 있는 방법들?, 
1. 방화벽?, UFW 방화벽을 설정하고 포트는 4242만 열어두기, DNF?
1. hostname 설정하는 방법들?
1. 인트라아이디를 유저명으로 하는 유저 생성, sudo와 user42 그룹에 포함
1. 강력한 비밀번호 정책사용하기
	- 현재 비밀번호는 30일 마다 소멸
	- 변경을 위해 기다려야 하는 기간은 최소 이틀로 설정
	- 비밀번호 소멸 7일 전에 경고 메시지
	- 비밀번호는 최소 10글자 이상, 대문자와 숫자를 포함, 같은 글자 3번 이상 연속되면 안됨, 유저명 포함x
	- 이전 비밀번호에 포함되지 않는 문자 최소 7개 이상
	- 루트 권한 비밀번호 또한 해당 규칙을 따라야 함.
1. sudo? sudo strict rules? 
	- sudo 인증 시, 비밀번호가 틀렸을 때 3번의 기회만 주어짐
	- sudo 권한 사용 중, 비밀번호가 틀렸을 때 설정한 오류 메시지가 출력
	- sudo 권한을 이용하여 수행한 명령어들 입출력 모두 기록되어야 함. log 파일로 `/var/log/sudo/` 폴더에 저장되어야함.
	- tty?, tty 모드는 활성화
	- sudo 권한으로 이용할 수 있는 폴더 경로는 반드시 제한
1. bash 환경에서 작동되는 monitoring.sh를 작성
	- cron? 10분 마다 작동되고 오류 발생 처리하기
	- 운영체제의 아키텍쳐와 커널 버전
	- 물리 프로세서의 개수
	- 가상 프로세서의 개수
	- 서버 내에서 사용가능한 램 가동률을 백분율로 표시
	- 서버 내에서 사용가능한 메모리 가동률을 백분율로 표시
	- 현재 프로세서 가동률을 백분율로 표시
	- 마지막 부팅 시간과 날짜
	- LVM이 활성화 되었는지 여부
	- 활성화된 연결 수
	- 서버를 사용하고 있는 유저 수
	- 서버의 IPv4 주소와 MAC (Media Access Control = 매체 접근 제어) 주소
	- sudo로 실행된 커맨드의 수
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