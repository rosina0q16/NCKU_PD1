#include <stdio.h>
#define maxN 305

int n, a;
int arr[maxN];

int meow(void)
{
    if (n == 1) {
        return 1;
    }
    for (int i = 1; i < maxN; i++) {
        if (!arr[i]) {
            continue;
        }
        arr[i]--;
        n--;
        for (int j = 1; j < maxN; j++) {
            if (arr[j] && arr[i + j]) {
                arr[j]--;
                arr[i + j]--;
                n -= 2;

                if (meow()) {
                    for (int k = 1; k < maxN; k++) {
                        if (arr[k]) {
                            a = k;
                            return 1;
                        }
                    }
                }
                arr[j]++;
                arr[i + j]++;
                n += 2;
            }
        }
        arr[i]++;
        n++;
    }
    return 0;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        arr[a]++;
    }

    if (meow()) {
        printf("%d", a);
    }
    return 0;
}