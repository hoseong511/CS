# What is Shell?
### **커널(kernel)**
- 운영 체제의 다른 부분 및 응용 프로그램 수행에 필요한 여러 가지 서비스를 제공함.
- 초기의 프로그램은 운영 체제의 지원을 받지 않고도 컴퓨터만으로 불러들인 다음 실행될 수 있었음.
- 다만 다른 프로그램을 실행하기 위해서는 컴퓨터의 전원을 껐다가 켬으로써 다시 입력자료를 읽어들여야 하는 방식 (원통형 테이프 같은 것을 갈아끼우는 이미지를 어디서 봤던것 같은데 찾질 못함..)
- 이러한 과정이 반복되면서 로더, 디버거와 같은 작은 프로그램들이 있는것이 다른 프로그램으로 교체하거나 새로운 프로그램을 개발하는 데 유리하다는 사실을 알게됨.
- 로더, 디버거들이 초기 운영 체제 커널 기초가 됨.

### **셸(Shell)**
- 운영체제의 커널(운영체제의 일부로 메모리에서 항상 동작하고 있는 프로그램)과 사용자 사이를 이어주는 역할
- shell은 사용자의 명령어를 해석하고 운영체제가 알아들을 수 있게 지시해줌. 운영체제는 shell에게 받은 지시를 하드웨어가 알아들을 수 있게 해줌.
- 셸의 종류
	- bash, sh, ksh, csh, ...

- #!/bin/bash
	- 사용하려는 명령어 해석기가 bash 셸 임을 미리 알려주는 것
	- #!은 스크립트의 제일 앞에서 이 파일이 어떤 명령어 해석기의 명령어 집합인지를 시스템에게 알려주는 역할
	- #!은 2 byte의 "매직넘버"로서, 실행 가능한 셸 스크립트라는 것을 나타내는 특별 표시자.
	- #! 바로 뒤에 나오는 것은 경로명, 스크립트 내 명령어를 해석할 프로그램 위치를 나타냄.