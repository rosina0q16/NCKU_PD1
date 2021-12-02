#include <stdio.h>

#define N 500
#define swap(x, y)   \
    {                \
        int tmp = x; \
        x = y;       \
        y = tmp;     \
    }

int size;
int array[N];

int partition(int a[], int low, int high)
{
    int p = a[high], s = low - 1;
    for (int i = low; i < high; i++) {
        if (a[i] <= p) {
            swap(a[i], a[s + 1]);
            s++;
        }
    }
    swap(a[high], a[s + 1]);
    return s + 1;
}
void quicksort(int arr[], int low, int high)
{
    if (low >= high)
        return;
    int mrk = partition(arr, low, high);
    for (int i = 0; i < size; i++) {
        if (i == low)
            printf("[ ");
        if (i == mrk)
            printf("*");
        printf("%d ", arr[i]);
        if (i == high)
            printf("] ");
    }
    puts("");

    quicksort(arr, low, mrk - 1);
    quicksort(arr, mrk + 1, high);
}

int main()
{
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    quicksort(array, 0, size - 1);

    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    puts("");
    return 0;
}
