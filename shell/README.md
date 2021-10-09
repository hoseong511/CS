# UNIX & LINUX env settings
## for Mac, for compile C lang, use a gcc

- ```grep -n ' ' ~/.bash``` : 찾는 문자열이 있으면 해당되는 행의 위치를 출력 
- ```-z $val``` : 문자열 길이가 0이면 True
- \> : 덮어쓰기
- \>\> : 이어 붙이기

## screen 사용하기
```sh
yum install screen
man screen #or screen -? <- 설치확인
screen -S [input session name] # screen 만 입력하면 default로 실행
screen -S [session name] -X quit # session 삭제
screen -list # screen list 출력
```
- `Ctrl+a` : 명령어를 입력하기 위한 pre-command 이다.
- pre-command 후, 
    - `|` : 가로 화면 분할
    - `S` : 세로 화면 분할
    - `Q` : 현재 화면을 제외 한 화면분할종료
    - `:remove` : 분할된 윈도우를 삭제
    - `c` : 새로운 쉘 실행
    - `"` : 실행중인 쉘 리스트확인
    - `tab` : 분할된 화면에서 이동 

## 한글 깨짐 해결하기
- 터미널에서
	- `locale`을 확인해보기
	- `env` 확인해보기
	- `/etc/profile` 확인해보기
	- UTF-8$ 또는 utf8$인지 확인을 해야한다.
	- 내 문제는 UTF-8이 없었다.
- vim에서
	- 간단하게 `set encoding=utf-8`로 해결
	- 인터넷을 찾아보니 `set fileencodigns=utf-8,cp949`도 해주라했는데 `/etc/vimrc`를 확인해보니 파일인코딩을 처리해주는 부분이 있었다.
	- 단, 사용되는 LANG이 UTF-8$이나 utf8$이어야 했다.

## ssh 접속 설정하기
- 접속을 해보니 서버로 150회 정도 접속시도를 한 로그를 확인했다. 다행히 공공 ip 접속 허용 설정을 해놓지는 않아서 hadoop이나 oracle 이름으로 접속을 하는 것은 자연스레 차단은 되는데 root(port:22, 물론 포트도 바꾸기는 했다)로 접속을 하는 것은 조금 불안했다.
- `last -f /var/lof/btmp` 접속 실패 로그 확인이다. `last` 명령어를 사용하면 접속 로그를 확인할 수 있다. (ip가 중국...)
- 재빨리 키를 만들고 패스워드 접속을 막아 놓을 필요가 있었다.
- 설정 경로는 ` /etc/ssh/sshd\_config`, PermitRootLogin, PasswordAuthentication, ChallengeResponseAuthentication 를 적절히 설정해주면 된다.
- 나는 root로 접속은 허용(`PermitRootLogin yes`)할 것이고, 비밀번호만 막을거다(`PasswordAuthentication no`).
- `service sshd reload`로 서비스 재시작하고 위 설정이 반영되었는지 접속을 해보자
