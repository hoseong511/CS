# **VariableConstance**

## **1. 변수와 상수**
### 1.1 변수
- 변할 수 있는 데이터
- 정수와 실수
    - 변수를 선언할 때는 자료형과 변수명을 입력한다.
    원하는 경우 초기값을 적용할 수 있다.
    - 가장 많이 사용되는 변수는 정수형(Integer) 변수이다.
    - 변수의 초기화와 쓰레기 값
        + 초기화 되지 않은 변수는 쓰레기 값이 들어간다.
        + Visual Studio는 기본적으로 초기화 되지 않은 변수를 감지하고 오류를 출력한다.
            ```C
                #include <stdio.h>
                
                int main(void) {
                    int a;
                    printf("The number is %d.\n", a);
                    system("pause");
                    return 0;
                }
            ```
            오류  발발생  
        + 정적 변수로 선언된 것은 기본적으로 0으로 값이 초기화 된다.
        + 정적 변수가 아닌 수를 0으로 초기화 하려면 값을 일일이 넣어주어야한다.

            ```C
                #include <stdio.h>
                
                int a;
                
                int main(void) {
                    printf("The number is %d.\n", a);
                    system("pause");
                    return 0;
                }
            ```

        
### 1.2 상수
- 변하지 않는 데이터
2. comment
    - 주석을 사용하는 법
        1. /* ㄱㄴㄷㄹㅁㅂㅅ */
        2. // ㄱㄴㄷㄹㅁㅂㅅ
    - 주석을 이용해서 코드에 대한 설명으로 활용한다.
