## **Super User Do**

### **sudoers**
- Defaults 옵션 중 
	- env_reset : `sudo` 명령어는 최소한의 환경 변수로 실행된다 `HOME`, `LOGNAME`, `PATH`, `SHELL`, `TERM`, `USER`, `MAIL`을 포함한.   
		- env_reset enable : env_keep 목록에 의해 호출된 사용자 환경에서 보존된 변수가 PAM 환경 변수보다 우선된다.   
		<br>

		- env_reset disable : 실행 중인 사용자 환경이 env_delete 목록의 패턴과 일치하지 않는 한 PAM 환경 변수보다 우선된다. 
		<br>

	- requiretty : `sudo` 명령어는 tty[^tty]로 로그인한 경우에만 실행된다. 크론이나 cgi-bin 스크립트에서는 명령어 실행을 제한한다.

	- 


[^tty]: In computing, tty is a command in Unix and Unix-like operating systems to print the file name of the terminal connected to standard input(사용중인 터미널을 의미).