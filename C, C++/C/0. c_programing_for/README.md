# C Programing for beginners
## TOC

## **C 개발 환경 on mac OS**

- xcode가 설치 됐다면 c compiler가 설치 되어 있음.

	- xcode 설치 하기

	- Appstore에서 xcode 검색

	- 설치

	- `gcc --version` 확인

- VScode 이용하기

	- extensions에서 C/C++ 검색 후 설치

	- 
- 메모리 누수 검사
	- 프로세스 번호 : `ps -ef | grep -i [프로그램이름]`
	- 메모리 누수 검사 : `while true; do leaks [프로세스번호]; sleep 0.5; done`