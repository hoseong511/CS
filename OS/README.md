## **π― κ°μλ¨Έμ  μ΄μ©, μλ² κ΅¬μΆ**

<br>

## **TOC**
**1. [μΌν μ€μ λ°λΉμ](#2-μΌν μ€μ-λ°λΉμ)**   
**2. [νν°μ](#3-νν°μ)**   
**3. [μλΉμ€](#4-μλΉμ€)**   
**4. [κ³μ  κ΄λ¦¬](#5-κ³μ -κ΄λ¦¬)**   
**5. [μλ² λͺ¨λν°λ§](#6-μλ²-λͺ¨λν°λ§)**   

<br>

### **1. μΌν μ€μ λ°λΉμ**

- [μΌν μ€, λ°λΉμ](https://hoseong511.github.io/CS/OS/debian)

- You must choose as an operating system either the latest stable version of Debian   

	β latest stable vsrsion([λ°λΉμ](https://wiki.debian.org/DebianReleases), [μΌν μ€](https://ko.wikipedia.org/wiki/CentOS#%EB%B2%84%EC%A0%84_%EB%82%B4%EC%97%AD)) λ° `cat /etc/os-release` νμΈ
	
   
GUI|CLI
:------------:|:------------:
![image](https://user-images.githubusercontent.com/62678380/146662111-abd8aff4-06ce-4ae3-92ba-9f83eaadf168.png)|![image](https://user-images.githubusercontent.com/62678380/146662144-da48e92a-e63e-481c-b5c8-fe78ce3f9d46.png)
μμΆλ ₯μ κ·Έλν½ νλ©΄μΌλ‘ μ¬μ©μμ μ»΄ν¨ν° μνΈμμ© | μμΆλ ₯μ νμ€νΈ νλ©΄μΌλ‘ μ¬μ©μμ μ»΄ν¨ν° μνΈμμ©

- you will install the minimum of services.   

	β μ»€λ§¨λ λΌμΈ μΈν°νμ΄μ€ νμΈ   
	<br>

- [CLI μ€μΉ κ³Όμ ](https://hoseong511.github.io/CS/OS/howto)
	<br>	

<br>

### **2. νν°μ**
- You must create at least 2 encrypted partitions using LVM. Below is an example of the expected partitioning   

	β `lsblk`λ‘ νμΈ   	

	β [lvm?](https://hoseong511.github.io/CS/OS/lvm)

	β [νν°μλ κ³Όμ ](https://hoseong511.github.io/CS/OS/howto#21-%EB%94%94%EC%8A%A4%ED%81%AC-%EC%84%A4%EC%A0%95--%ED%8C%8C%ED%8B%B0%EC%85%98---%EC%95%94%ED%98%B8%ED%99%94%EB%90%9C-lvm-%EC%84%A0%ED%83%9D)

	<br>

<br>

### **3. μλΉμ€**

μλΉμ€ | μ€λͺ
:--------:|:--------
AppArmor	| MAC μ μ± μ΄μ©ν νμΌμ κ·Ό κΆν, μ€νκΆνμ λΆλ¦¬
apt	| Advanced Package Tool; ν₯μλ ν¨ν€μ§ κ΄λ¦¬ λκ΅¬
aptitude | apt κΈ°λ₯μ νλ‘ νΈ νλ©΄ λ° νΈλ¦¬ κΈ°λ₯ μΆκ°
sudo	| μ¬μ©μμκ² μ νλ root κΆνμ μ€
ssh	| μΈλΆ λ¨Έμ μ λ³΄μ μ μμ μν λ³΄μ μΈ
ufw	| λ°©νλ²½
cron	| ν¬λ‘ νμ΄λΈμ μ§μ λμ΄ μλ λλ‘ νΉμ  νλ‘κ·Έλ¨μ μ€ννλ λ°λͺ¬

- must be running at startup and its configuration has to be adapted for the projectβs needs. AppArmor for Debian must be running at startup too.   
   
	β AppArmor(`aa-status`) μλ νμΈ 
<br>

- AppArmor   
   
	β [LINK](https://hoseong511.github.io/CS/OS/apparmor)
<br>

- aptμ aptitudeμ μ°¨μ΄   
	![image](https://user-images.githubusercontent.com/62678380/146716325-38dee88e-e280-4b7b-9f38-cb3a3fa5de7b.png)
	β [LINK](https://hoseong511.github.io/CS/OS/apt)
<br>

- A SSH service will be running on port 4242 only. For security reasons, it must not be possible to connect using SSH as root.   

	β 4242 ν¬νΈ νμΈ, root μ μ λΆκ° νμΈ(passwd λλ λΉλ°ν€ λ λ€ νμΈ)   
	β [μ€μΉ λ° μ€μ  κ³Όμ ](https://hoseong511.github.io/CS/OS/ssh)   
<br>

- The use of SSH will be tested during the defense by setting up a new account.   

	β κ³μ  μΆκ°νκ³  μ μν΄λ³΄κΈ°   
<br>

- You have to configure your operating system with the UFW firewall and thus leave only port 4242 open.   

	β UFW μλνμΈ λ° 4242ν¬νΈ μ΄λ €μλμ§ νμΈ(`ufw status`) 
	<br>

<br>

### **4. κ³μ  κ΄λ¦¬**
- The `hostname` of your virtual machine must be your login ending with 42 (e.g., wil42). You will have to modify this hostname during your evaluation.   

	β λ‘κ·ΈμΈλ ν μ μ λͺ@`hostname` νμΈ, hostname λ°κΎΌ ν μ μ©λμλμ§ νμΈ   
	<br>

- νμ¬ hossong μ΄λΌλ μ μ κ° μλμ§ νμΈ, ν΄λΉ μ μ κ° κ·Έλ£Ή `user42`, `sudo`μ μλμ§ νμΈ

- You have to implement a strong password policy.

	- Your password has to expire every 30 days.

	- The minimum number of days allowed before the modification of a password will be set to 2.

	- The user has to receive a warning message 7 days before their password expires.

	- Your password must be at least 10 characters long. It must contain an uppercase letter and a number. Also, it must not contain more than 3 consecutive identical characters.(3 μ΄κ³Ό) [3 or more](https://www.google.com/search?q=3+or+more&oq=3+or+more&aqs=chrome..69i57j0i512l3j0i30l6.1671j1j7&sourceid=chrome&ie=UTF-8) 3 μ΄μ

	- The password must not include the name of the user.

	- The following rule does not apply to the root password: The password must have at least 7 characters that are not part of the former password.

	- Of course, your root password has to comply with this policy.

	- λΉλ°λ²νΈ λ§λ£ λ©μμ§ μλ¦Ό 7μΌ, λ§λ£ κΈ°κ° 30μΌ, λ³κ²½ μ, μ΅μ 2μΌ ν λ³κ²½

	- μ μ΄λ 10μ, μ λ/μ λ¬Έμ λ° μ«μ μ μ΄λ 1μ μ΄μ, μ΄μ  λΉλ°λ²νΈμμ μ μ΄λ 7μ μ΄μ λ³κ²½, μ μ λͺ ν¬ν¨ x, κ΄λ¦¬μ κ³μ λ λΉλ°λ²νΈ μ μ± μ μ©

	<br>

- κ³μ μ΄ μ κ·μΉμ λ°λ₯΄κ³  μλμ§?

	β κΈ°κ° κ·μΉ νμΈ(`/etc/login.def` ,`chage -l μ μ λͺ`)   

	β μ κ·μΉ μ μ© λΉλ² root : Qwert12345qwe, hossong : Qwert12345qwe    

	β κ·μΉ μλ° λΉλ² :   
	```
		1(10μ λ―Έλ§),   

		abc6988asdqwqwqw(λλ¬Έμx)  λ°λλκ±° νμΈ β  abc6988ASDQwqwqw

		qqqqW13246(κ°μλ¬Έμ3μκΉμ§νμ©)  λ°λλκ±° νμΈ β  qqqeW13246

		hossong956676A(μ μ λͺx)   λ°λλκ±° νμΈ β  hosso956676A
		rootABX956676(μ μ λͺx)   λ°λλκ±° νμΈ β  rooABX956676
		
		qweqwe56676A(7μμ΄μλ°λμ§μμ) λ°λλκ±° νμΈ β qweqwer6676A 
	```
	<br>

- You have to install and configure sudo following strict rules.

	- Authentication using sudo has to be limited to 3 attempts in the event of an incorrect password.

	- A custom message of your choice has to be displayed if an error due to a wrong password occurs when using sudo.

	- Each action using sudo has to be archived, both inputs and outputs. The log file has to be saved in the `/var/log/sudo/` folder.

	- The TTY mode has to be enabled for security reasons.

	- For security reasons too, the paths that can be used by sudo must be restricted. 

	- sudo λΉλ² νλ¦΄ μ 3λ² κΈ°ν, λΉλ² νλ¦΄ μ λ΄κ° μμ±ν λ©μμ§ μλ¦Ό, λͺλ Ήμ΄ μ/μΆλ ₯ λ‘κ·Έ, tty λͺ¨λ νμΈ, λ³΄μ λͺ¨λ μ μ©

	<br>

<br>

### **5. μλ² λͺ¨λν°λ§**
- cron? 10λΆ λ§λ€ μλλκ³  μ€λ₯ λ°μ μ²λ¦¬νκΈ°

	- μ΄μμ²΄μ μ μν€νμ³μ μ»€λ λ²μ  

	- λ¬Όλ¦¬ νλ‘μΈμμ κ°μ 

	- κ°μ νλ‘μΈμμ κ°μ 

	- μλ² λ΄μμ μ¬μ©κ°λ₯ν λ¨ κ°λλ₯ μ λ°±λΆμ¨λ‘ νμ 

	- μλ² λ΄μμ μ¬μ©κ°λ₯ν λ©λͺ¨λ¦¬ κ°λλ₯ μ λ°±λΆμ¨λ‘ νμ 

	- νμ¬ νλ‘μΈμ κ°λλ₯ μ λ°±λΆμ¨λ‘ νμ

	- λ§μ§λ§ λΆν μκ°κ³Ό λ μ§ 

	- LVMμ΄ νμ±ν λμλμ§ μ¬λΆ 

	- νμ±νλ μ°κ²° μ 

	- μλ²λ₯Ό μ¬μ©νκ³  μλ μ μ  μ 

	- μλ²μ IPv4 μ£Όμμ MAC (Media Access Control = λ§€μ²΄ μ κ·Ό μ μ΄) μ£Όμ 

	- sudoλ‘ μ€νλ μ»€λ§¨λμ μ 

	<br>

- 10λΆ λ§λ€ μ μλνλμ§, ν΄λΉ μμ μ’λ£κΉμ§ ν  μ μλμ§? 
	β λ©μΈμ§ λ³΄λ΄λ κ³μ μ΄ `root`μΈμ§ νμΈ
- ss -tnulp