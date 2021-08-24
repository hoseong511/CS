# **C lang**
## 0. c언어와 컴퓨터
  - 컴퓨터는 일련의 연산을 수행하는 ```계산기``` 이다.
  - 알아야 할 부분들은 아래와 같다.
    ```md
    1. 누가 명령어를 읽는지?
    2. 어디서 명령어를 읽는지?
    3. 프로그램이 무엇인지?
    4. 명령어는 어떻게 작성하는지?
    ```

1. 누가 명령어를 읽는지?   
    - 컴퓨터의 모든 연산은 중앙 처리 장치, CPU(Central Processing Unit)가 읽는다.
    - 그랙픽 관련 연산들만 전문적으로 처리하는 GPU라는 장치가 따로 있다.
    - 범용적인 명령어들의 경우는 모두 CPU에서 처리한다.

2. 어디서 명령어를 읽는지?   
    - 명령어를 실행하기 위해서는 두 가지 조건이 필요하다.
    - 첫 번째로는 실행할 명령어를 읽어야 하고, 두번째로 연산된 결과를 저장할 공간이 필요하다.
    - CPU가 연산을 수행하기 위해서 데이터를 저장하는 공간을 레지스터(register)라고 부른다. (64비트 CPU의 경우 레지스터는 총 16개 -> 최대 16 * 8byte(=64bit) = 128byte)
    - CPU의 저장 공간 역할을 하는 장치를 바로 램(RAM; Random Access Memory)이다.(휘발성 메모리)
    - 하드디스크와 SSD(비휘발성 메모리)
      ![](https://modoocode.com/img/c/cpuramhdd.png)
      
3. 명령어는 어떻게 작성하는지? 
    - 주소값
  

## 1. Vscode C lang settings 
  - [link](https://justdoitproject.tistory.com/m/31)
  - 상위 디렉토리에 task.json을 설정하면 하위 디렉토리에서 동일한 환경으로 빌드할 수 있다.
  - ~~scanf 다루기가 쉽지않다. 그냥 xcode 이용하자..~~
  - 라고 생각했으나 Code Runner라는 extension을 설치하자.
  - 오른쪽 마우스 누른 후 run code를 하거나, control + option + N 을 누르면 실행된다.
  - 그리고 설정에서 ```code runner terminal``` 검색 후 ```Whether to run code in Intergrated Terminal.```을 체크해주면 scanf를 이용할 수 있다. (터미널로 결과를 출력한다.)