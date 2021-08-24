# **기본 입출력**
## scanf()로 입력해보기
  - scanf()
    - C언어에서 특정한 변수에 값을 넣기 위해서 scanf를 이용
    - mac에서는 ```system("pause")```가 안된다.
    - Visual Studio는 기본적으로 취약한 함수를 사용할 수 없도록 제한한다. (scanf는 취약함수!)   
       ```#define _CRT_SECURE_NO_WARNINGS```를 추가한다.
    - &를 이용하는 이유는 주소 연산자이기에 scanf에서 이용한다.(포인터에서 더욱 자세히 설명될 예정)
