# **운영체제 구조**

## 응용 프로그램, 운영체제, 컴퓨터 하드웨어(시스템 리소스)
- 운영체제
- 응용프로그램 
- 컴퓨터 하드웨어
- 운영체제의 역할
    - 응용프로그램은 운영체제에게 컴퓨터 하드웨어(시스템 리소스)을 요청함.
    - 운영체제는 적절한 시스템 리소스를 찾아서, 응용프로그램에게 제공함.
    - 응용프로그램 작업이 종료되면, 운영체제가 해당 시스템 리소스를 회수함.
## 응용프로그램, 운영체제, 컴퓨터 하드웨어 관계
- 운영체제는 응용 프로그램이 요청하는 메모리를 허가하고, 분배함.
- 운영체제는 응용 프로그램이 요청하는 CPU시간을 제공함.
- 운영체제는 응용 프로그램이 요청하는 IO Devices 사용을 허가/제어함.

## 운영체제는 사용자 인터페이스 제공
- 쉘(Shell)
    - 사용자가 운영체제 기능과 서비스를 조작할 수 있도록 인터페이스를 제공하는 프로그램
    - 쉘은 터미널 환경(CLI)과, GUI 환경 두 종류로 분류함

## 운영체제는 응용 프로그램에게 인터페이스 제공
- API(Application Programming Interface)
    - 각 프로그래밍 언어별 인터페이스 제공
    - 함수로 제공
    - open(), write(), ...
- 보통은 라이브러리(library) 형태로 제공
    - C library
    - https://www.gnu.org/software/libc/

### 시스템 콜   
- 시스템 콜 또는 시스템 호출 인터페이스
- 운영체제가 운영체제 각 기능을 사용할 수 있도록 시스템 콜이라는 명령 또는 함수를 제공
- API 내부에는 시스템콜을 호출하는 형태로 만들어지는 경우가 대부분임.
     
## 운영체제를 만든다면?
1. 운영체제를 개발(kernel: 핵심 기능을 갖고 있는 소프트웨어)
2. 시스템 콜을 개발
3. C API (library)
4. Shell 프로그램
5. 응용 프로그램 개발

## 운영체제와 시스템 콜
- 시스템 콜 정의 예
    - POSIX API(UNIX API와 유사), WINDOWS API
> API: 각 언어별 운영체제 기능 호출 인터페이스 함수 (각 언어별 인터페이스)   
> 시스템 콜: 운영체제 기능을 호출하는 함수

## 정리
- 운영체제는 컴퓨터 하드웨어와 응용 프로그램을 관리함.
- 사용자 이너페이스를 제공하기 위해 쉘 프로그램을 제공함.
- 응용 프로그램이 운영체제 기능을 요청하기 위해서, 운영체제는 시스템 콜을 제공함.
    - 보통 시스템 콜을 직접 사용하기 보다는, 해당 시스템 콜을 사용해서 만든 각 언어별 라이브러리(API)를 사용함.

-----
## CPU Protection Rings
- CPU도 권한 모드라는 것을 가지고 있음
    - 사용자 모드 (User mode by applications): 응용 프로그램이 사용
    - 커널 모드 (kernel mode by OS): 특권 명령어 실행과 원하는 작업 수행을 위한 접근을 가능케하는 모드, OS가 사용
> kernel이란? OS의 핵심기능 소프트웨어를 일컫는다.   
> shell 이란? 커널의 껍데기 소프트웨어
- 권한 별로 접근할 수 있는 자원이 달라지는 개념(커널모드의 경우 핵심자원(특권)에 접근, 사용자모드는 접근 불가)

## 응용 프로그램과 운영체제
- 대부분의 프로그램 개발은 사용자 영역에서 이루어짐.
- 응용 프로그램이 시스템 리소스의 직접 접근이 불가, 반드시 시스템 호출 인터페이스(운영체제 제공)를 통해야 함. -> CPU Protection Rings 참조

## 시스템 콜은 커널 모드로 실행
- 커널 모드에서만 실행 가능한 기능들이 있음
- 커널 모드로 실행하려면, 반드시 시스템 콜을 사용해야 함.
- 시스템 콜은 운영체제 제공

## 사용자 모드와 커널 모드
- 함부로 응용 프로그램이 전체 컴퓨터 시스템 리소스에 접근 불가
- 파일을 읽어들이기(DISK접근) 위해서는 open()이라는 시스템 콜을 해야만 함.
    - 응용 프로그램이 open()을 이용하지 않고 파일을 읽어들이기 불가

## Code example1
```c
#include <unistd.h>

int main()
{
    int fd;
    fd = open("data.txt".O_RODNLY);
    if (fd == -1) 
    {
        prinf("Error: can not ope file\n");
    }
}
// open전까지는 사용자 모드 
```

## 정리
- 운영체제는 **시스템 콜** 제공
- 프로그래밍 언어별로 운영체제 기능을 활용하기 위해, 시스템 콜을 기반으로 API제공
- 응용 프로그램은 운영체제 기능 필요시, 해당 **API**를 사용해서 프로그램을 작성
- 응용 프로그램이 실행되서, 운영체제 기능이 필요한 API를 호출하면, 시스템 콜이 호출되서, **커널모드로** 변경되어 OS 내부에서 해당 명령이 실행되고, 다시 응용 프로그램으로 돌아감.  

---

## 프로세스 스케쥴링
### - 배치 처리 시스템, 시분할 시스템, 멀티 태스킹

## 배치 처리 시스템
![image](https://user-images.githubusercontent.com/62678380/140599862-8fe4b2ed-5478-499a-8ab2-2b96e9320922.png)

- Application1 작업을 완료한 후 Application2를 실행함. 
- queue와 유사함.

## 배치 처리 시스템과 시분할 시스템/멀티 프로그래밍 비교
- 여러 프로그램을 순차적으로 실행함
    - 어떤 프로그램 실행 시간 길다면, 다른 프로그램이 실행되기까지 해당 시간을 기다려야함.
    - 동시에 여러 프로그램 실행
    - 다중 사용자 지원

> 멀티프로그래밍/시분할 시스템 도입

## 시분할 시스템
- 다중사용자 지원을 위해 컴퓨터 응답 시간을 최소화 하는 시스템
   
![image](https://user-images.githubusercontent.com/62678380/140600138-7c99b093-cc20-4a97-b8c8-9206d3f78b3c.png)

## 멀티 태스킹
- 단일 CPU에서, 여러 응용 프로그램이 동시에 실행되는 것처럼 보이도록 하는 시스템
    - MP3음악을 들으며, 문서 작성을 함.
    - 사람이 인지 못할 정도의 시간으로 작업을 쪼개서 동시에 실행되는 것처럼 작동됨.

## 실제 멀티 태스킹
- 1000 밀리초(ms) = 1초
- 10 ~ 20 ms 단위로도 실행 응용 프로그램이 전환
- 사용자에게는 동시에 실행되는 것처럼 보임.

## 멀티 태스킹과 멀티 프로세싱
- 멀티 태스킹은 단일 CPU
- 멀티 프로세싱은 여러 CPU에 하나의 프로그램을 병렬로 실행해서 실행속도를 극대화시킴

## 정리
- 배치 처리 시스템
- 시분할 시스템(다중 사용자 지원, 응답 시간 최소화)
- 멀티 태스킹 (동시 실행하는 것 처럼 보임)
- 멀티 프로세싱

---

## 멀티 프로그래밍
- 최대한 CPU를 많이 활용하도록 하는 시스템
    - 시간 대비 CPU활용도를 높임.
    - 응용 프로그램을 짧은 시간 안에 실행 완료를 시킬 수 있음.
- 응용 프로그램은 온전히 CPU를 쓰기 보다, 다른 작업을 중간에 필요로 하는 경우가 많음.
    - 응용 프로그램 실행 도중 파일을 읽어들임(저장 장치 접근)
    - 응용 프로그램이 실행되다가 프린팅.   
    - example
        ```c
        #include <unistd.h>

        int main()
        {
            int fd;
            fd = open("data.txt).O_RDONLY);
            if(fd == -1)
            {
                printf("Error: can not open file\n");
                return 1;
            }
            else
            {
                printf("File opened and now close.\n");
                close(fd);
                return ();
            }
        }
        ```
        ![image](https://user-images.githubusercontent.com/62678380/140633758-3495b60e-731f-4d67-aa89-04a7aebe3d97.png)
    - 메모리 계층 
        [![image](https://user-images.githubusercontent.com/62678380/140640207-c711c5e7-8da3-413d-9671-c45a37e58ab6.png)](http://computationstructures.org/lectures/caches/caches.html)
        출처: http://computationstructures.org/lectures/caches/caches.html
    - System bus 
        ![image](https://user-images.githubusercontent.com/62678380/140640293-d60264e7-e26a-4e62-a969-3e2bce854f0b.png)   
        저장매체에는 DMA(Direct Memory Access)가 접근함.

## 정리
> 실제로는 시분할 시스템, 멀티 프로그래밍, 멀티 태스킹이 유사한 의미로 통용됨.
- 여러 응용 프로그램 실행을 가능하게함.
- 응용 프로그램이 동시에 실행되는 것처럼 보이도록 함.
- CPU를 쉬지 않고 응용 프로그램을 실행토록 해서, 짧은 시간 안에 응용 프로그램이 실행 완료될 수 있도록 함.
- 컴퓨터 응답 시간도 짧게 해서, 다중 사용자도 지원
> 시분할 시스템: 다중 사용자 지원, 컴퓨터 응답시간을 최소화하는 시스템   
> 멀티 태스킹: 단일 CPU에서 여러 응용 프로그램을 동시에 실행하는 것처럼 보이게 하는 시스템   
> 멀티 프로세싱: 여러 CPU에서 하나의 응용 프로그램을 병렬로 실행하게 해서, 실행속도를 높이는 기법   
> 멀티 프로그래밍: 최대한 CPU를 일정 시간당 많이 활용하는 시스템

----

# 스케쥴링 알고리즘
## 스케쥴링 알고리즘 기본

## 프로세스란(process)?
- 실행 중인 프로그램을 프로세스라고 함.
    - 메모리에 올려져서, 실행 중인 프로그램
    - 코드 이미지(바이너리): 실행 파일, 예:ELF format
> 프로세스라는 용어는 작업, task, job이라는 용어와 혼용

- 응용 프로그램 != 프로세스
    - 응용 프로그램은 여러 개의 프로세스로 이루어지는 경우
- 하나의 응용 프로그램은 여러 개의 프로세스(프로그램)가 상호작용을 하면서 실행될 수 있음

> 간단한 C/C++ 프로그램을 만든다면 -> 하나의 프로세스   
> 여러 프로그램을 만들어서, 서로 통신하면서 프로그램을 작성할 수 있음(IPC기법)

## 스케쥴러와 프로세스
- 프로세스 실행 관리는 스케쥴러가 함.

## 스케쥴링 알고리즘
> 어느 순서대로 프로세스를 실행시킬까?
- 목표
    - 시분할 시스템 예: 프로세스 응답 시간을 가능한 짧게
    - 멀티 프로그래밍 예: CPU 활용도를 최대로 높혀서, 프로세스를 빠르게 실행

## FIFO 스케쥴러
> 프로세스가 저장매체를 읽는 다ㄴ든지, 프린팅을 하는 작업 없이 연속으로 CPU를 처음부터 끝까지 사용한다.
- 가장 간단한 스케쥴러 (배치 처리 시스템)
    ![image](https://user-images.githubusercontent.com/62678380/140762061-30b6ae0b-f066-435e-9e87-36c4c0871eb7.png)
- FCFS (First Come First Served) 스케쥴러
    ![image](https://user-images.githubusercontent.com/62678380/140762298-dabe77e8-767e-4f41-89bb-b098da5c9114.png)

## 최단 작업 우선(SJF) 스케쥴러
- SJF(Shortest Job First) 스케쥴러
    ![image](https://user-images.githubusercontent.com/62678380/140763225-45c7df97-0740-409d-92df-8761d7b0c458.png)

