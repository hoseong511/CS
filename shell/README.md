# Simple command!  compile and excute

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
    - `Q` : 화면분할종료
    - `c` : 새로운 쉘 실행
    - `"` : 실행중인 쉘 리스트확인
    - `tab` : 분할된 화면에서 이동 

