#include <stdio.h>

int n;
char txt[65];

void swap(char str[], int begin, int end)
{
    for (int i = begin, j = (begin + end) / 2 + 1; i <= (begin + end) / 2; i++) {
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        j++;
    }
}
void rotate(char str[], int x, int begin, int end)
{
    x = x % (end - begin + 1);
    char tmp[65] = "";
    tmp[64] = '\0';

    for (int i = begin; i <= end; i++) {
        int j = (i + x);
        if (j > end) {
            j -= (end - begin + 1);

        } else if (j < begin) {
            j += (end - begin + 1);
        }
        tmp[j] = str[i];
    }
    for (int i = begin; i <= end; i++) {
        str[i] = tmp[i];
    }
}
void rail(char str[], int mv[], int x, int begin, int end)
{
    char tmp[65];
    tmp[64] = '\0';

    for (int i = begin / x; i <= end / x; i++) {
        for (int j = 0; j < x; j++) {
            int k = mv[j] + i * x - 1;
            tmp[k] = str[i * x + j];
        }
        for (int j = 0; j < x; j++) {
            str[i * x + j] = tmp[i * x + j];
        }
    }
}
void caesar(char str[], int x, int begin, int end)
{
    x %= 26;
    for (int i = begin; i <= end; i++) {
        int j = str[i] + x;
        if (str[i] >= 'a' && str[i] <= 'z') {
            if (j < 'a')
                str[i] = j + 26;
            else if (j > 'z')
                str[i] = j - 26;
            else
                str[i] = j;
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            if (j < 'A')
                str[i] = j + 26;
            else if (j > 'Z')
                str[i] = j - 26;
            else
                str[i] = j;
        }
    }
}
void trithemius(char str[], int x, int y, int begin, int end)
{
    for (int i = begin; i <= end; i++) {
        x %= 26;
        int j = str[i] + x;
        if (str[i] >= 'a' && str[i] <= 'z') {
            if (j < 'a')
                str[i] = j + 26;
            else if (j > 'z')
                str[i] = j - 26;
            else
                str[i] = j;
            if (y == 1) { // increasing
                x++;
            } else { // decreasing
                x--;
            }
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            if (j < 'A')
                str[i] = j + 26;
            else if (j > 'Z')
                str[i] = j - 26;
            else
                str[i] = j;
            if (y == 1) { // increasing
                x++;
            } else { // decreasing
                x--;
            }
        }
    }
}
void vigenere(char str[], char mv[], int x, int begin, int end)
{
    int arr[50];
    for (int i = 0; i < x; i++) {
        if (mv[i] >= 'a' && mv[i] <= 'z') {
            arr[i] = mv[i] - 'a';
        } else {
            arr[i] = mv[i] - 'A';
        }
    }
    for (int i = begin, j = 0; i <= end; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            int k = str[i] + arr[j % x] % 26;
            if (k > 'z') {
                str[i] = k - 26;
            } else if (k < 'a') {
                str[i] = k + 26;
            } else {
                str[i] = k;
            }
            j++;
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            int k = str[i] + arr[j % x] % 26;
            if (k > 'Z') {
                str[i] = k - 26;
            } else if (k < 'A') {
                str[i] = k + 26;
            } else {
                str[i] = k;
            }
            j++;
        }
    }
}

void f1()
{
    swap(txt, 0, 63);
    caesar(txt, 13, 0, 31);
    char v[5] = "meow";
    vigenere(txt, v, 4, 32, 63);

    rotate(txt, -3, 0, 63);
}
void f2()
{
    rotate(txt, 11, 0, 63);
    trithemius(txt, 74, 1, 0, 63);
    rotate(txt, 1, 0, 31);
    rotate(txt, 3, 32, 63);
    int v[8] = { 4, 3, 1, 2, 7, 6, 5, 8 };
    rail(txt, v, 8, 0, 63);
}
void f3()
{
    int v1[4] = { 3, 2, 4, 1 };
    rail(txt, v1, 4, 0, 63);
    caesar(txt, 8, 0, 31);
    int v2[8] = { 1, 8, 4, 3, 6, 5, 7, 2 };
    rail(txt, v2, 8, 32, 63);
    swap(txt, 0, 63);
    trithemius(txt, 602, 0, 0, 63);
    rotate(txt, 7, 0, 63);
}
void f4()
{
    char v1[10] = "vigenere";
    vigenere(txt, v1, 8, 0, 31);
    swap(txt, 0, 31);
    trithemius(txt, 3, 1, 0, 31);
    rotate(txt, -24, 32, 63);
    rotate(txt, 19, 0, 63);
}
void f5()
{
    int v1[8] = { 3, 1, 7, 6, 4, 5, 2, 8 };
    rail(txt, v1, 8, 0, 63);
    caesar(txt, 10, 0, 31);
    int v2[4] = { 2, 4, 1, 3 };
    rail(txt, v2, 4, 32, 63);
    swap(txt, 0, 63);
    trithemius(txt, 52, 1, 0, 63);
    rotate(txt, 7, 0, 63);
}
int main()
{
    txt[64] = '\0';

    scanf("%d", &n);
    getchar();
    for (int i = 0; i < 64; i++) {
        scanf("%c", &txt[i]);
    }

    if (n == 1)
        f1();
    else if (n == 2)
        f2();
    else if (n == 3)
        f3();
    else if (n == 4)
        f4();
    else
        f5();

    printf("%s\n", txt);
    return 0;
}