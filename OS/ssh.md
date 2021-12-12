## 시큐어 셸(SSH)서비스 이용하기
### **시큐어 셸 클라이언트**
- [시큐어 셸(ssh)](https://hoseong511.github.io/CS/OS/ssh)?
- 텔넷?
#### **OpenSSH**
- 데비안 설치 시, 추가적으로 소프트웨어를 설치했던 부분이 있다. 시큐어 셸 접속을 가능하게 해준다.
	![image](https://user-images.githubusercontent.com/62678380/145525960-874b449d-39dd-4795-91e5-192d397e4035.png)
- 버추얼 박스에서 포트포워딩하기   
	![image](https://user-images.githubusercontent.com/62678380/145710862-726c9baa-e84d-4643-9d1b-f0b084e17d40.png)   
	![image](https://user-images.githubusercontent.com/62678380/145710924-3fc0095b-c952-409d-b9b9-62db1bf76635.png)   
- 게스트 포트번호는 22 
	![image](https://user-images.githubusercontent.com/62678380/145711154-58d79b57-e52c-4c4e-a0bf-1c24d109ed3e.png)
- 호스트 포트번호를 바꿔주면 그 번호로 접속해야함 -> 22번을 안쓰는것이 보안상 좋음.
- 현재 컴퓨터 터미널에 ssh 클라이언트가 설치되어있는지 확인하자.   
	```sh
	ssh -V	#OR man ssh
	# > OpenSSH_8.1p1, LibreSSL 2.7.3
	```
- 바로 접속
	```sh
	ssh [user@]hostname -p [port번호]
	#OR ssh ssh://[user@]hostname[:port]
	```   

- 접속 정보를 등록하는 과정, yes를 해주자
	![image](https://user-images.githubusercontent.com/62678380/145711358-3b12824f-da90-4c69-8d61-47061a490a01.png)

- 접속이 완료된 화면   
	![image](https://user-images.githubusercontent.com/62678380/145711538-68792152-12ce-4033-969a-1b27bf247dd8.png)

- 비밀키 만들기
	```sh
	ssh-keygen # default : rsa
	```
	[![asciicast](https://asciinema.org/a/XjjtIw7eCr78zaCmPprElhZWt.svg)](https://asciinema.org/a/XjjtIw7eCr78zaCmPprElhZWt)
- 비밀키를 깃헙에 올리지 말자 (클라우드 플랫폼 비밀키라면 더더욱이..!)
- 비밀키로 접속하기   
	```sh
	ssh -i [비밀키정보] [user@]hostname -p [port번호]
	#OR ssh ssh://[user@]hostname[:port]
	```   
- 권한설정을 하라는 메시지   
	![image](https://user-images.githubusercontent.com/62678380/145712275-57519ae5-2228-4af4-86bd-32aceef66e46.png)
- `chmod 600 privatekey`
- 혹시 비밀번호를 물어본다면 `~/.ssh/`에서 `authorized_keys`를 확인해주자 
	- `/etc/ssh/sshd_config`를 확인해보면 `#AuthorizedKeysFile	.ssh/authorized_keys .ssh/authorized_keys2`인 부분
	- default값이 authorized_key이므로 해당 이름으로 바꿔주면 된다
	- 만약 `id_rsa.pub`으로 하고 싶다면?
	- 주석해제하고 `id_rsa.pub` 적어주자
- 접속완료   
	![image](https://user-images.githubusercontent.com/62678380/145712564-89e55f38-508c-4e12-af1d-821225790eb9.png)

#### **Putty**
- 