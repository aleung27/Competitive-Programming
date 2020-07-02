#include <bits/stdc++.h>

using namespace std;

char grid[8][8];
int current = 0;
char path[] = {"IEHOVA#"};
int dx[] = {1, -1, 0};
int dy[] = {0, 0, -1};
pair<int, int> start, finish;

void dfs(pair<int, int> at, int h, int w) {
    for(int i = 0; i < 3; i++) {
        if(at.first + dx[i] < 0 || at.first + dx[i] >= w || at.second +dy[i] < 0 || at.second + dy[i] >= h) {
            continue;
        }

        if(grid[at.second + dy[i]][at.first+dx[i]] == path[current]) {
            current++;
            if(i == 0) printf("right");
            else if (i == 1) printf("left");
            else printf("forth");

            path[current-1] == '#' ? printf("\n") : printf(" ");
            dfs({at.first+dx[i], at.second+dy[i]}, h, w);
        }
    }
}

int main () {
    int n;
    scanf("%d", &n);

    for(;n >0; n--) {
        int h, w;
        scanf("%d %d", &h, &w);

        memset(grid, '0', 8*8);
        current = 0;

        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                scanf(" %c", &grid[i][j]);
                if(grid[i][j] == '@') {
                    start.first = j;
                    start.second = i;
                } else if (grid[i][j] == '#') {
                    finish.first = j;
                    finish.second = i;
                }
            }
        }
        
        dfs(start, h, w);
    }

    return 0;
}