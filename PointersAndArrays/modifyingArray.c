#include <stdio.h>
#define SIZE 201

void modify_array(int*);

int main(void)
{
    int arr[SIZE] = {};
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }
    modify_array(&arr[SIZE / 2]);
    for (int i = 1; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
// 0  1  2  3  4  5  6  7  8
//
void modify_array(int* p)
{
    int* s;
    p -= (SIZE / 2);
    if (*p == 1) {
        for (s = p + 1; s < p + SIZE; s += 2) {
            *s += 10;
        }

    } else if (*p == 2) {
        for (s = p + 1; s < p + SIZE; s += 3) {
            *s *= 8;
        }
    } else { // p == 3
        for (s = p + 1; s < p + SIZE; s += 5) {
            *s -= 2;
        }
    }
    return;
}