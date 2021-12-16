## **TTY**
- tty : 터미널
- pts : 가짜 터미널
<br>

### **역사 속 텔레프린터**
- 텔레프린터를 사용해 유선으로 메시지를 보내고 받을 수 있었다. 기존 모스 부호 통신을 대체함.
- 1908년에 텔레프린터가 상업용으로 출시함. 그게 바로 TTY, Teletyperwriter의 약자
<br>

	![Teletyperwriter](https://i0.wp.com/itsfoss.com/wp-content/uploads/2021/12/WACsOperateTeletype.jpg?w=429&ssl=1)
	사진은 2차세계대전에 사용된 텔레타이퍼

### Linux에서 TTY는?
- UNIX 및 Linux의 추상 장치이다. 직렬 포트와 같은 물리적 입력 장치를 가리키고 때로는 사용자가 시스템과 상호 작용할 수 있도록 하는 가상 TTY를 의미한다.

	``` 
	CTRL + ATL + (fn+)F1 : 잠금화면
	CTRL + ATL + (fn+)F2 : 데스크탑
	CTRL + ATL + (fn+)F3 : TTY3
	CTRL + ATL + (fn+)F4 : TTY4
	CTRL + ATL + (fn+)F5 : TTY5
	CTRL + ATL + (fn+)F6 : TTY6
	```

	![image](https://user-images.githubusercontent.com/62678380/146299355-41e9bd1b-6b97-4efb-b8e7-19490e994464.png)

### **pseudo terminal(pts)**
- 터미널 에뮬레이터 프로그램
- 호스트 입장에서 가짜 터미널임
<br>

### **Reference**
- [https://www.howtogeek.com/428174/what-is-a-tty-on-linux-and-how-to-use-the-tty-command/](https://www.howtogeek.com/428174/what-is-a-tty-on-linux-and-how-to-use-the-tty-command/)
- [https://itsfoss.com/what-is-tty-in-linux/](https://www.howtogeek.com/428174/what-is-a-tty-on-linux-and-how-to-use-the-tty-command/)
- [https://unix.stackexchange.com/questions/4126/what-is-the-exact-difference-between-a-terminal-a-shell-a-tty-and-a-con](https://unix.stackexchange.com/questions/4126/what-is-the-exact-difference-between-a-terminal-a-shell-a-tty-and-a-con)