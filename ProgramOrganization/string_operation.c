#include <stdio.h>
#define maxN 500000

char str[maxN] = "", opera[16] = "";
char c;
int op, cnt, cnt_c, j;

void COMPRESS()
{
    char tmp = '\t';
    char st2[maxN] = "";
    cnt_c = 0, j = 0;
    for (int i = 0; i < cnt; i++) {
        if (str[i] == tmp) {
            cnt_c++;
            if (i == cnt - 1) {
                if (cnt_c < 10) {
                    st2[j] = cnt_c + '0';
                    j++;
                } else if (cnt_c < 100) {
                    st2[j + 1] = cnt_c % 10 + '0';
                    st2[j] = cnt_c / 10 + '0';
                    j += 2;
                } else if (cnt_c < 1000) {
                    st2[j + 2] = cnt_c % 10 + '0';
                    cnt_c /= 10;
                    st2[j + 1] = cnt_c % 10 + '0';
                    st2[j] = cnt_c / 10 + '0';
                    j += 3;
                } else {
                    st2[j + 3] = cnt_c % 10 + '0';
                    cnt_c /= 10;
                    st2[j + 2] = cnt_c % 10 + '0';
                    cnt_c /= 10;
                    st2[j + 1] = cnt_c % 10 + '0';
                    st2[j] = cnt_c / 10 + '0';
                    j += 4;
                }
            }
        } else {
            if (j != 0) {
                if (cnt_c < 10) {
                    st2[j] = cnt_c + '0';
                    j++;
                } else if (cnt_c < 100) {
                    st2[j + 1] = cnt_c % 10 + '0';
                    st2[j] = cnt_c / 10 + '0';
                    j += 2;
                } else if (cnt_c < 1000) {
                    st2[j + 2] = cnt_c % 10 + '0';
                    cnt_c /= 10;
                    st2[j + 1] = cnt_c % 10 + '0';
                    st2[j] = cnt_c / 10 + '0';
                    j += 3;
                } else {
                    st2[j + 3] = cnt_c % 10 + '0';
                    cnt_c /= 10;
                    st2[j + 2] = cnt_c % 10 + '0';
                    cnt_c /= 10;
                    st2[j + 1] = cnt_c % 10 + '0';
                    st2[j] = cnt_c / 10 + '0';
                    j += 4;
                }
            }
            cnt_c = 1;
            tmp = str[i];
            st2[j] = '-';
            st2[j + 1] = str[i];
            j += 2;
            if (i == cnt - 1) {
                if (cnt_c < 10) {
                    st2[j] = cnt_c + '0';
                    j++;
                } else if (cnt_c < 100) {
                    st2[j + 1] = cnt_c % 10 + '0';
                    st2[j] = cnt_c / 10 + '0';
                    j += 2;
                } else if (cnt_c < 1000) {
                    st2[j + 2] = cnt_c % 10 + '0';
                    cnt_c /= 10;
                    st2[j + 1] = cnt_c % 10 + '0';
                    st2[j] = cnt_c / 10 + '0';
                    j += 3;
                } else {
                    st2[j + 3] = cnt_c % 10 + '0';
                    cnt_c /= 10;
                    st2[j + 2] = cnt_c % 10 + '0';
                    cnt_c /= 10;
                    st2[j + 1] = cnt_c % 10 + '0';
                    st2[j] = cnt_c / 10 + '0';
                    j += 4;
                }
            }
        }
    }
    for (int i = 0; i < maxN; i++) {
        str[i] = '\0';
    }
    for (int i = 0; i < j; i++) {
        str[i] = st2[i];
    }
    cnt = j;
    str[cnt] = '\0';
    printf("%s\n", str);

    printf("cnt = %d\n", cnt);
}
void REVERSE()
{
    for (int i = 0; i < (cnt + 1) / 2; i++) {
        char tmp = str[i];
        str[i] = str[cnt - i - 1];
        str[cnt - i - 1] = tmp;
    }
    printf("%s\n", str);
}
void TO_UPPER()
{
    for (int i = 0; i < cnt; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        }
    }
    printf("%s\n", str);
}
void TO_LOWER()
{
    for (int i = 0; i < cnt; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 'a' - 'A';
        }
    }
    printf("%s\n", str);
}
void REMOVETAR()
{
    char target;
    scanf("%c", &target);
    getchar();
    for (int i = 0; i < cnt; i++) {
        if (str[i] == target) {
            cnt--;
            for (int j = i; j < cnt; j++) {
                str[j] = str[j + 1];
            }
            str[cnt] = '\0';
            i--;
        }
    }
    printf("%s\n", str);
}

int main()
{
    cnt = 0;
    scanf("%c", &c);
    while (c != '\n') {
        str[cnt] = c;
        cnt++;
        scanf("%c", &c);
    }

    str[cnt] = '\0';

    scanf("%d", &op);
    getchar();
    for (int i = 0; i < op; i++) {
        scanf("%s", opera);
        getchar();
        // PRINT
        if (opera[3] == 'N') {
            printf("%s\n", str);
        } else if (opera[3] == 'P') {
            COMPRESS();
        } else if (opera[3] == 'E') {
            REVERSE();
        } else if (opera[3] == 'U') {
            TO_UPPER();
        } else if (opera[3] == 'L') {
            TO_LOWER();
        } else if (opera[3] == 'O') {
            REMOVETAR();
        }
    }
    return 0;
}