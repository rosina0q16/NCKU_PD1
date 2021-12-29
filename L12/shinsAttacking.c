#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1024

void convert_to_polar(int* coords, int N);

int main()
{
    int N, coords[MAX_N + 1][2];
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d%d", &coords[i][0], &coords[i][1]);

    convert_to_polar((int*)coords, N);

    return 0;
}

void convert_to_polar(int* coords, int N)
{
    for (int i = 0; i < N; i++) {
        double x = (*(coords + i * 2)) * 1.0, y = (*(coords + i * 2 + 1)) * 1.0;
        double deg;
        if (!(x == 0))
            deg = atan2(y, x) * 180.0 / M_PI;
        if ((x > 0 && y > 0) || (x < 0 && y > 0)) {
            printf("%.2f ", deg);
        } else if ((x > 0 && y < 0) || (x < 0 && y < 0)) {
            printf("%.2f ", deg + 360.0);
        } else if (x == 0) {
            if (y > 0)
                printf("90.00 ");
            else
                printf("270.00 ");
        } else if (y == 0) {
            if (x > 0)
                printf("0.00 ");
            else
                printf("180.00 ");
        }
        printf("%.2f\n", pow((y * y + x * x), 0.5));
    }
}
