#include <stdio.h>
int* report_card(int* s);

int main()
{
    int score[1001];
    int* show;
    int count = 0;

    do {
        scanf("%d", &score[count++]);
    } while (score[count - 1] != -1);

    show = report_card(score);

    count = 0;
    while (*(show + count) != -1) {
        printf("%d ", *(show + count));
        count++;
    }
}

int* report_card(int* s)
{
    int *meow, *end;
    int cnt = 0, tmp = 0, tmp_val = 0, val = 0;

    for (meow = s; meow < s + 1001; meow++) {
        if (*meow != -1) {
            if (*meow < 60) {
                if (tmp > cnt || (tmp == cnt && tmp_val > val)) {
                    cnt = tmp;
                    end = meow;
                    val = tmp_val;
                }
                tmp = 0;
                tmp_val = 0;
            } else {
                tmp++;
                tmp_val += *meow;
            }
        } else {
            if (tmp > cnt || (tmp == cnt && tmp_val > val)) {
                cnt = tmp;
                end = meow;
                val = tmp_val;
            }
            break;
        }
    }
    *end = -1;
    return (end - cnt);
}