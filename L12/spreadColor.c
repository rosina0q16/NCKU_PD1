#include <stdio.h>
#define M 5
#define N 8
char colors[4] = { 'R', 'G', 'B', 'X' }; // Red, Green, Blue, Empty

void spread(char*, int, int);

int main(void)
{
    char graph[M][N];
    int row, col;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++)
            scanf("%c", &graph[i][j]);
        getchar(); // Ignore '\n'
    }
    scanf("%d %d", &row, &col); // Starting position

    spread(&graph[0][0], row, col);

    // Print out the spreading result
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++)
            printf("%c", graph[i][j]);
        printf("\n");
    }
    return 0;
}
void spread(char* graph, int row, int col)
{
    // up and down
    char color = *(graph + 8 * row + col);

    printf("color = %c\n", color);

    for (int i = row - 1; i >= 0; i--) {
        if (*(graph + 8 * i + col) == 'X') {
            *(graph + 8 * i + col) = color;
        } else if (*(graph + 8 * i + col) != color) {
            break;
        }
    }
    for (int i = row + 1; i < 5; i++) {
        if (*(graph + 8 * i + col) == 'X') {
            *(graph + 8 * i + col) = color;
        } else if (*(graph + 8 * i + col) != color) {
            break;
        }
    }
    // left and right
    for (int i = col - 1; i >= 0; i--) {
        if (*(graph + 8 * row + i) == 'X') {
            *(graph + 8 * row + i) = color;
        } else if (*(graph + 8 * row + i) != color) {
            break;
        }
    }
    for (int i = col + 1; i < 8; i++) {
        if (*(graph + 8 * row + i) == 'X') {
            *(graph + 8 * row + i) = color;
        } else if (*(graph + 8 * row + i) != color) {
            break;
        }
    }
}