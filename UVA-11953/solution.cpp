#include <bits/stdc++.h>

using namespace std;

bool seen[105][105];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(vector<vector<int>>& grid, pair<int, int> at, int n) {
    if(seen[at.first][at.second]) return;
    seen[at.first][at.second] = true;

    for(int i = 0; i < 4; i++) {
        if(at.first + dy[i] < 0 || at.first + dy[i] >= n || at.second + dx[i] < 0 || at.second + dx[i] >= n) {
            continue;
        }

        if(grid[at.first + dy[i]][at.second + dx[i]] == 'x' || grid[at.first + dy[i]][at.second + dx[i]] == '@') {
            dfs(grid, {at.first+dy[i], at.second+dx[i]}, n);
        }
    }

}

void check_sunk(vector<vector<int>>& grid, pair<int, int> at, int n, int& sunk) {
    seen[at.first][at.second] = true;

    for(int i = 0; i < 4; i++) {
        if(at.first + dy[i] < 0 || at.first + dy[i] >= n || at.second + dx[i] < 0 || at.second + dx[i] >= n) {
            continue;
        }

        if(grid[at.first + dy[i]][at.second + dx[i]] == 'x' && !seen[at.first + dy[i]][at.second + dx[i]]) {
            sunk = 0;
            check_sunk(grid, {at.first + dy[i], at.second + dx[i]}, n, sunk);
        } else if(grid[at.first + dy[i]][at.second + dx[i]] == '@' && !seen[at.first + dy[i]][at.second + dx[i]]) {
            check_sunk(grid, {at.first + dy[i], at.second + dx[i]}, n, sunk);
        }
    }
}

int main () {
    int t;
    char next;
    scanf("%d", &t);

    int tcase = 1;
    for(; t > 0; t--) {
        int n;
        scanf("%d", &n);

        vector<vector<int>> grid;
        memset(seen, false, 105*105*sizeof(bool));

        for(int i = 0; i < n; i++) {
            vector<int> row;
            for(int j = 0; j < n; j++) {
                scanf(" %c", &next);
                if(next == '.') seen[i][j] = true;
                row.push_back(next);
            }
            grid.push_back(row);
        }

        int counter = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!seen[i][j]) {
                    dfs(grid, {i, j}, n);
                    counter++;
                }
            }
        }

        memset(seen, false, 105*105*sizeof(bool));
        int sunkcount = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '@' && !seen[i][j]) {
                    int sunk = 1;
                    check_sunk(grid, {i, j}, n, sunk);
                    if (sunk) sunkcount++;
                }
            }
        }

        printf("Case %d: %d\n", tcase, counter-sunkcount);
        tcase++;
    }


    return 0;
}