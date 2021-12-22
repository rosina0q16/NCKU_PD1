#include <stdio.h>

void addition();

void print_binary(void* n)
{
    for (int i = 31; i >= 0; --i) {
        printf("%d", (*(int*)n >> i) & 1);
        if (i && !(i % 8))
            printf(" ");
    }
}

int main()
{
    addition();
    return 0;
}
float a, b, c;
int car = 0, tmp = 0, s = 0;
void addition()
{
    scanf("%f%f", &a, &b);
    printf("   ");
    print_binary(&a);
    printf("\n+) ");
    print_binary(&b);
    printf("\n---------------------------------------\n   ");

    for (int i = 0; i <= 31; i++) {
        int aa = (*(int*)&a >> i) & 1;
        int bb = (*(int*)&b >> i) & 1;
        tmp = aa ^ bb ^ car;
        s = tmp << i | s;
        if (aa & bb || aa & car || bb & car) {
            car = 1;
        } else {
            car = 0;
        }
    }
    print_binary(&s);
    printf("\n%d + %d = %d\n", (int)a, (int)b, s);
}