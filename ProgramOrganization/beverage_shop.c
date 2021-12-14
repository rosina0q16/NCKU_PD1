#include <stdio.h>

int arr[7], sl[5] = { 0, 3, 5, 7, 10 }, il[5] = { 0, 30, 50, 70, 100 };
int n, s, i, rev;
char bev1, bev2;

int sugar(int s)
{
    if (arr[5] - sl[s - 1] >= 0) {
        return 1;
    }
    return 0;
}
int ice(int i)
{
    if (arr[6] - il[i - 1] >= 0) {
        return 1;
    }
    return 0;
}

int main()
{
    for (int i = 0; i < 7; i++) {
        scanf("%d", &arr[i]);
        arr[i] *= 1000;
    }
    scanf("%d", &n);
    getchar();
    for (int k = 0; k < n; k++) {
        scanf("%c%c %d/%d", &bev1, &bev2, &s, &i);
        getchar();
        if (bev1 == 'B' && bev2 == ' ') {
            if (arr[0] >= 500 && sugar(s) && ice(i)) {
                rev += 20;
                arr[0] -= 500;
                arr[5] -= sl[s - 1];
                arr[6] -= il[i - 1];
            }
        } else if (bev1 == 'W' && bev2 == ' ') {
            if (arr[1] >= 500 && sugar(s) && ice(i)) {
                rev += 15;
                arr[1] -= 500;
                arr[5] -= sl[s - 1];
                arr[6] -= il[i - 1];
            }
        } else if (bev1 == 'T' && bev2 == ' ') {
            if (arr[2] >= 500 && sugar(s) && ice(i)) {
                rev += 30;
                arr[2] -= 500;
                arr[5] -= sl[s - 1];
                arr[6] -= il[i - 1];
            }
        } else if (bev1 == 'G' && bev2 == ' ') {
            if (arr[3] >= 500 && sugar(s) && ice(i)) {
                rev += 20;
                arr[3] -= 500;
                arr[5] -= sl[s - 1];
                arr[6] -= il[i - 1];
            }
        } else if (bev1 == 'G' && bev2 == 'T') {
            if (arr[2] >= 250 && arr[3] >= 250 && sugar(s) && ice(i)) {
                rev += 45;
                arr[2] -= 250;
                arr[3] -= 250;
                arr[5] -= sl[s - 1];
                arr[6] -= il[i - 1];
            }
        } else if (bev1 == 'W' && bev2 == 'T') {
            if (arr[2] >= 350 && arr[1] >= 150 && sugar(s) && ice(i)) {
                rev += 40;
                arr[2] -= 350;
                arr[1] -= 150;
                arr[5] -= sl[s - 1];
                arr[6] -= il[i - 1];
            }
        } else if (bev1 == 'B' && bev2 == 'M') {
            if (arr[0] >= 200 && arr[4] >= 300 && sugar(s) && ice(i)) {
                rev += 35;
                arr[0] -= 200;
                arr[4] -= 300;
                arr[5] -= sl[s - 1];
                arr[6] -= il[i - 1];
            }
        } else if (bev1 == 'T' && bev2 == 'M') {
            if (arr[2] >= 200 && arr[4] >= 300 && sugar(s) && ice(i)) {
                rev += 45;
                arr[2] -= 200;
                arr[4] -= 300;
                arr[5] -= sl[s - 1];
                arr[6] -= il[i - 1];
            }
        } else { // WM
            if (arr[1] >= 200 && arr[4] >= 300 && sugar(s) && ice(i)) {
                rev += 30;
                arr[1] -= 200;
                arr[4] -= 300;
                arr[5] -= sl[s - 1];
                arr[6] -= il[i - 1];
            }
        }
    }
    for (int i = 0; i < 7; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n%d", rev);
}