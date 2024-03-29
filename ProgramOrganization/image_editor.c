#include <stdio.h>
#define maxN 105
int m, n, op, l, r, up, low, t;
char d, c;
int arr[maxN][maxN];
void rotate(char dir)
{
    if (t == 0)
        return;
    int ar2[maxN][maxN];
    int tmp = m;
    m = n;
    n = tmp;
    if (dir == 'r') {
        for (int i = 0; i < m; i++) {
            for (int j = 0, y = n - 1; j < n; j++, y--) {
                ar2[i][j] = arr[y][i];
            }
        }

    } else { // dir == 'l'
        for (int i = 0; i < m; i++) {
            for (int j = 0, y = 0; j < n; j++, y++) {
                ar2[i][j] = arr[y][m - i - 1];
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = ar2[i][j];
        }
    }
    t--;
    rotate(dir);
}
void vertical_mirror()
{
    for (int i = 0; i < m / 2; i++) {
        for (int j = 0; j < n; j++) {
            int tmp = arr[i][j];
            arr[i][j] = arr[m - i - 1][j];
            arr[m - i - 1][j] = tmp;
        }
    }
}
void horizontal_mirror()
{
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n / 2; j++) {
            int tmp = arr[i][j];
            arr[i][j] = arr[i][n - 1 - j];
            arr[i][n - 1 - j] = tmp;
        }
    }
}
void crop(int left, int right, int upper, int lower)
{
    n = right - left + 1;
    m = lower - upper + 1;
    int ar2[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            ar2[i][j] = arr[upper - 1 + i][left - 1 + j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = ar2[i][j];
        }
    }
}
int main()
{
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    scanf("%d", &op);
    getchar();
    for (int i = 0; i < op; i++) {

        scanf("%c", &c);
        getchar();

        if (c == 'r') {
            scanf("%c %d", &d, &t);
            t %= 4;
            getchar();
            rotate(d);
        } else if (c == 'v') {
            vertical_mirror();
        } else if (c == 'h') {
            horizontal_mirror();
        } else if (c == 'c') {
            scanf("%d %d %d %d", &l, &r, &up, &low);
            crop(l, r, up, low);
            getchar();
        } else { // cin >> print
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    printf("%d ", arr[i][j]);
                }
                puts("");
            }
            puts("");
        }
    }
    return 0;
}
