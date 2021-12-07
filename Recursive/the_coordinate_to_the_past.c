#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxN 10001
char arr[maxN];

int h2d(char ch)
{
    if (ch >= '0' && ch <= '9')
        return ch - '0';
    if (ch >= 'a' && ch <= 'f')
        return ch - 'a' + 10;
    return ch - 'A' + 10;
}

char* d2h(int a)
{
    char* ar2 = (char*)malloc(sizeof(char) * maxN);
    int idx = 0;
    char tmp;

    while (a) {
        if (a % 16 >= 10) {
            ar2[idx] = a % 16 + 'a' - 10;
        } else {
            ar2[idx] = a % 16 + '0';
        }
        a /= 16;
        idx++;
    }
    ar2[idx] = '\0';

    for (int i = 0; i < idx / 2; i++) {
        tmp = ar2[idx - i - 1];
        ar2[idx - i - 1] = ar2[i];
        ar2[i] = tmp;
    }
    return ar2;
}

void meow(char str[])
{
    int odd = 0, even = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (i % 2) {
            odd += h2d(str[i]);
        } else {
            even += h2d(str[i]);
        }
    }
    if (odd < 16) {
        printf("%x", odd);
    } else {
        meow(d2h(odd));
    }
    if (even < 16) {
        printf("%x", even);
    } else {
        meow(d2h(even));
    }
}

int main()
{
    scanf("%s", arr);
    meow(arr);
    return 0;
}