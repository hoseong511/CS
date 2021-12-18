## **🎯 제안 규칙 따라 첫 서버 구축**

<br>

## **TOC**
**1. [GUI와 CLI](#1-GUI와-CLI)**   
**2. [데비안과 센토스](#2-데비안과-센토스)**   
**3. [파티션](#3-파티션)**   
**4. [설치한 서비스 확인](#4-설치한-서비스-확인)**   
**5. [계정 관리](#5-계정-관리)**   

<br>

### **1. GUI와 CLI**
- you will install the minimum of services.   

	→ 커맨드 라인 인터페이스 확인
	<br>

<br>

### **2. 데비안과 센토스**
- You must choose as an operating system either the latest stable version of Debian   

	→ [데비안](https://ko.wikipedia.org/wiki/%EB%8D%B0%EB%B9%84%EC%95%88#%EB%B0%B0%ED%8F%AC_%EC%97%AD%EC%82%AC) 또는 [센토스](https://ko.wikipedia.org/wiki/CentOS#%EB%B2%84%EC%A0%84_%EB%82%B4%EC%97%AD) latest stable vsrsion인지 확인
	<br>

- OS를 선택한 이유?   **todo: 개인용 서버와 회사용 서버에 대한 설명, 페도라 계열과 데비안으로 나눠서 설명하기**   

	→ [LINK](https://hoseong511.github.io/CS/OS/debian)
	<br>

<br>

### **3. 파티션**
- You must create at least 2 encrypted partitions using LVM. Below is an example of the expected partitioning   

	→ `lsblk`로 확인   
	→ [파티셔닝한 과정](https://hoseong511.github.io/CS/OS/howto#21-%EB%94%94%EC%8A%A4%ED%81%AC-%EC%84%A4%EC%A0%95--%ED%8C%8C%ED%8B%B0%EC%85%98---%EC%95%94%ED%98%B8%ED%99%94%EB%90%9C-lvm-%EC%84%A0%ED%83%9D)
	<br>

<br>

### **4. 설치한 서비스 확인**
- must be running at startup and its configuration has to be adapted for the project’s needs. AppArmor for Debian must be running at startup too.   
   
	→ SELinux(`sestatus`) 또는 AppArmor(`aa-status`) 작동 확인 
<br>

- SELinux와 AppArmor의 차이   
   
	→ [LINK](https://hoseong511.github.io/CS/OS/apparmor)
<br>

- apt와 aptitude의 차이   **todo : apt vs aptitude 비교 자료 만들기**   

	→ [LINK](https://hoseong511.github.io/CS/OS/apparmor)
<br>

- A SSH service will be running on port 4242 only. For security reasons, it must not be possible to connect using SSH as root.   

	→ 4242 포트 확인, root 접속 불가 확인(passwd 또는 비밀키 둘 다 확인)   
	→ [설치 및 설정한 과정](https://hoseong511.github.io/CS/OS/ssh)   
<br>

- The use of SSH will be tested during the defense by setting up a new account.   

	→ 계정 추가하고 접속해보기   
<br>

- You have to configure your operating system with the UFW firewall and thus leave only port 4242 open.   

	→ UFW 작동확인 및 4242포트 열려있는지 확인(`ufw status`) **todo : ufw vs firewall(centos) 내용 공부하기**   
<br>

<br>

### **5. 계정 관리**
- The `hostname` of your virtual machine must be your login ending with 42 (e.g., wil42). You will have to modify this hostname during your evaluation.   

	→ 로그인된 후 유저명@`hostname` 확인, hostname 바꾼 후 적용되었는지 확인   
	<br>

- You have to implement a strong password policy.

	- Your password has to expire every 30 days.

	- The minimum number of days allowed before the modification of a password will be set to 2.

	- The user has to receive a warning message 7 days before their password expires.

	- Your password must be at least 10 characters long. It must contain an uppercase letter and a number. Also, it must not contain more than 3 consecutive identical characters.(3 초과) [3 or more](https://www.google.com/search?q=3+or+more&oq=3+or+more&aqs=chrome..69i57j0i512l3j0i30l6.1671j1j7&sourceid=chrome&ie=UTF-8) 3 이상

	- The password must not include the name of the user.

	- The following rule does not apply to the root password: The password must have at least 7 characters that are not part of the former password.

	- Of course, your root password has to comply with this policy.

	<br>

- 계정이 위 규칙을 따르고 있는지?

	→ 기간 규칙 확인(`/etc/login.def` ,`chage -l 유저명`) **todo: chage 로 기간규칙 바꾸기와 /etc/login.def에 규칙 설정하는 내용 및 이외 규칙 정리**
	→ 위 규칙 적용 비번 root : Qwert12345qwe, hossong : Qwert12345qwe    
	→ 규칙 위반 비번 : qwer1234(10자 미만), qwert12345(대문자x), qqqqw12345(같은문자3자까지하용), hossong12345(유저명x), Qwert12678900(7자이상바뀌지않음;Qwert1678900a) 
	<br>

- You have to install and configure sudo following strict rules.

	- Authentication using sudo has to be limited to 3 attempts in the event of an incorrect password.

	- A custom message of your choice has to be displayed if an error due to a wrong password occurs when using sudo.

	- Each action using sudo has to be archived, both inputs and outputs. The log file has to be saved in the `/var/log/sudo/` folder.

	- The TTY mode has to be enabled for security reasons.

	- For security reasons too, the paths that can be used by sudo must be restricted. **todo: securepath 악용 사례 정리**

	<br>

<br>

### **6. 서버 모니터링**
- cron? 10분 마다 작동되고 오류 발생 처리하기 **todo : 크론 실행 시 오류 처리 `2 > /dev/null`

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

	<br>

- 10분 마다 잘 작동하는지, 해당 작업 종료까지 할 수 있는지? 
	→ 메세지 보내는 계정이 `root`인지 확인
