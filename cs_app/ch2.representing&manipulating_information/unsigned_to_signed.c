#include <stdio.h>
#include <limits.h>

int main(void)
{
    short v = -12345;
    unsigned short    uv = (unsigned int) v;
    printf("v = %d, uv = %u\n", v, uv);

    unsigned int    u = 4294967295;
    int tu = (int) u;
    printf("u = %u, tu = %d\n", u, tu);
    printf("x = %d, Umax = %u  --- (int) Umax = %d\n", -1, UINT_MAX, (int) UINT_MAX);

    /* c에서 부호형과 비부형의 비교*/
    int tx, ty;
    unsigned ux, uy;

    tx = (int) ux;
    uy = (unsigned) ty; // 명시적인 방법

    tx = ux;
    uy = ty; // 묵시적인 방법..

    int x = -1;
    unsigned    u = 2147483648;

    printf("x = %u = %d\n", x, x);
    printf("x = %u = %d\n", u, u);
}
