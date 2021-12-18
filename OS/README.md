## **🎯 목표**
제안된 규칙을 따라 첫 서버를 구축하기

## **TOC**
**1. [GUI와 CLI](#GUI와-CLI)**   
**2. [데비안과 센토스](#데비안과-센토스)**   
**3. [파티션](#파티션)**   
**4. [설치한 서비스 확인](#설치한-서비스-확인)**   
**5. [계정 관리](#데비안과-센토스)**   


### **1. GUI와 CLI**
- you will install the minimum of services.   

	→ 커맨드 라인 인터페이스 확인
	<br>


### **2. 데비안과 센토스**
- You must choose as an operating system either the latest stable version of Debian   

	→ [데비안](https://ko.wikipedia.org/wiki/%EB%8D%B0%EB%B9%84%EC%95%88#%EB%B0%B0%ED%8F%AC_%EC%97%AD%EC%82%AC) 또는 [센토스](https://ko.wikipedia.org/wiki/CentOS#%EB%B2%84%EC%A0%84_%EB%82%B4%EC%97%AD) latest stable vsrsion인지 확인
	<br>

- OS를 선택한 이유?   **todo: 개인용 서버와 회사용 서버에 대한 설명, 페도라 계열과 데비안으로 나눠서 설명하기**   

	→ [LINK](https://hoseong511.github.io/CS/OS/debian)
	<br>


### **3. 파티션**
- You must create at least 2 encrypted partitions using LVM. Below is an example of the expected partitioning   

	→ `lsblk`로 확인   
	→ [파티셔닝한 과정](https://github.com/hoseong511/CS/blob/main/OS/howto.md#21-%EB%94%94%EC%8A%A4%ED%81%AC-%EC%84%A4%EC%A0%95--%ED%8C%8C%ED%8B%B0%EC%85%98---%EC%95%94%ED%98%B8%ED%99%94%EB%90%9C-lvm-%EC%84%A0%ED%83%9D)
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


### **5. 계정관리**
- The `hostname` of your virtual machine must be your login ending with 42 (e.g., wil42). You will have to modify this hostname during your evaluation.   

	→ 로그인된 후 유저명@`hostname` 확인, hostname 바꾼 후 적용되었는지 확인   
<br>


