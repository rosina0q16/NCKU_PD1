#include <stdio.h>
#define NUM 9

void check_sudoku(int grid_p[][NUM])
{
    int mrk[9][9] = { 0 };
    for (int i = 0; i < NUM; i++) {
        for (int j = 0; j < NUM; j++) {
            for (int k = 0; k < NUM; k++) {
                //check col and row
                if ((grid_p[i][j] == grid_p[k][j] && i != k) || (grid_p[i][j] == grid_p[i][k] && j != k)) {
                    if (!mrk[i][j]) {
                        printf("(%d,%d)\n", i, j);
                        mrk[i][j] = 1;
                        break;
                    }
                }
            }
            int x = i / 3, y = j / 3;
            if (!mrk[i][j]) {
                for (int k = x * 3; k < x * 3 + 3; k++) {
                    for (int l = y * 3; l < y * 3 + 3; l++) {
                        if (i == k && j == l) {
                            continue;
                        } else if (grid_p[i][j] == grid_p[k][l]) {

                            printf("(%d,%d)\n", i, j);
                            mrk[i][j] = 1;
                            break;
                        }
                    }
                }
            }
        }
    }
}

int main(void)
{
    int grid[NUM][NUM]; // sudoku puzzle
    for (int i = 0; i < NUM; ++i) {
        for (int j = 0; j < NUM; ++j) {
            scanf("%d", &grid[i][j]);
        }
    }
    check_sudoku(grid);
    return 0;
}
