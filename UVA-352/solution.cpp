#include <bits/stdc++.h>

using namespace std;

bool seen[630];
int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

void dfs(int node, int n) {
    if(seen[node]) return;
    seen[node] = true;

    int x, y;
    x = node/n;
    y = node % n;
    for(int i = 0; i < 8; i++) {
        if(x + dx[i] < 0 || x + dx[i] >= n || y + dy[i] < 0 || y + dy[i] >= n) {
            continue;
        }

        if(!seen[(x+dx[i])*n + (y+dy[i])]) {
            dfs((x+dx[i])*n + (y+dy[i]), n);
        }
    }
}

int main () {
    int counter = 1;

    while(1) {
        int n;
        if(scanf("%d", &n) == EOF) break;
        int grid[n][n];

        memset(seen, false, 630);

        char next;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                scanf(" %c", &next);
                grid[i][j] = next -'0';
                if(grid[i][j] == 0) seen[i*n + j] = true;
            }
        }

        int eagles = 0;
        for(int i = 0; i < n*n; i++) {
            if(!seen[i]) {
                dfs(i, n);
                eagles++;
            }
        }

        printf("Image number %d contains %d war eagles.\n", counter, eagles);
        counter++;
    }

    return 0;
}