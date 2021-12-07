#include <stdio.h>
#define maxN 5005

int n, c;
int arr[maxN];

void pre(int x)
{
    printf("%d ", arr[x]);
    if (2 * x <= n) {
        pre(2 * x);
    }
    if (2 * x + 1 <= n) {
        pre(2 * x + 1);
    }
}
void in(int x)
{
    if (x * 2 <= n) {
        in(x * 2);
    }
    printf("%d ", arr[x]);
    if (x * 2 + 1 <= n) {
        in(x * 2 + 1);
    }
}
void post(int x)
{
    if (x * 2 <= n) {
        post(x * 2);
    }
    if (x * 2 + 1 <= n) {
        post(x * 2 + 1);
    }
    printf("%d ", arr[x]);
}

int main()
{
    scanf("%d\n%d", &c, &n);
    arr[0] = -1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    if (c == 0) { // pre-order
        pre(1);
    } else if (c == 1) { //in-order
        in(1);
    } else { // c == 2   post-order
        post(1);
    }
    return 0;
}