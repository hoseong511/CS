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

## 한글 꺠짐 해결하기
- 터미널에서
	- `locale`을 확인해보기
	- `env` 확인해보기
	- `/etc/profile` 확인해보기
	- UTF-8$ 또는 utf8$인지 확인을 해야한다.
	- 내 문제는 UTF-8이 없었다.
- vim에서
	- 간단하게 `set encoding=utf-8`로 해결
	- 인터넷을 찾아보니 `set fileencodigns=utf-8,cp949도 해주라했는데 `/etc/vimrc`를 확인해보니 파일인코딩을 처리해주는 부분이 있었다.
	- 단, 사용되는 LANG이 UTF-8$이나 utf8$이어야 했다.

