#include <stdbool.h>
#include <stdio.h>
#define n 5
// TODO: fill the route matrix with 0's or 1‘s.
// If there isn't any route, return false; otherwise, return true.
int dx, dy;
int dir[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
int vis[n][n] = { 0 };
bool visit(char maze[][n], int route[][n], int originX, int originY)
{
    route[originX][originY] = 1;
    vis[originX][originY] = 1;
    if (originX == n - 1 && originY == n - 1)
        return 1;
    for (int i = 0; i < 4; i++) {

        dx = originX + dir[i][0];
        dy = originY + dir[i][1];
        if (dx >= 0 && dx < n && dy >= 0 && dy < n && maze[dx][dy] == 'r' && !vis[dx][dy]) {
            if (visit(maze, route, dx, dy)) {
                return 1;
            }
        }
    }
    route[originX][originY] = 0;
    return 0;
}

int main(void)
{
    char maze[n][n];
    int route[n][n];
    // initialize maze and route matrices
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            route[i][j] = 0;
            scanf("%c", &maze[i][j]);
            getchar();
        }
    }
    if (visit(maze, route, 0, 0)) { // (0,0) is a starting point
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                printf("%d ", route[i][j]);
            printf("\n");
        }
    } else {
        printf("Can't find the exit!");
    }
    return 0;
}