#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define X real()
#define Y imag()
#define EPS 0.000000001
#define M_PI 3.14159265358979323846
#define CROSSPROD(a, b) (conj(a)*b).Y
#define FASTIO ios::sync_with_stdio(false);

int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};

bool seen[21][21] = {{false}};
char grid[21][21];
int biggest = INT_MIN;
int counter = 0;

template <class T>
T gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

void dfs(pair<int, int> at, int vert, int horiz, char land) {
    seen[at.first][at.second] = true;
    counter++;

    for(int i = 0; i < 4; i++) {
        if(at.first + dy[i] < 0 || at.first + dy[i] >= vert) continue;
        else if(at.second + dx[i] < 0 && grid[at.first+dy[i]][horiz-1] == land && !seen[at.first+dy[i]][horiz-1]) {
            dfs({at.first+dy[i], horiz-1}, vert, horiz, land);
        }
        else if(at.second + dx[i] == horiz && grid[at.first+dy[i]][0] == land && !seen[at.first+dy[i]][0]) {
            dfs({at.first+dy[i], 0}, vert, horiz, land);
        } else if(grid[at.first+dy[i]][at.second+dx[i]] == land && !seen[at.first+dy[i]][at.second+dx[i]]){
            dfs({at.first+dy[i], at.second+dx[i]}, vert, horiz, land);
        }
    }
}

int main () {
    while(1){
        int vert, horiz;
        char land;
        if(scanf("%d %d", &vert, &horiz) == EOF) break;
        memset(grid, '.', 21*21);
        memset(seen, false, 21*21*sizeof(bool));
        biggest = INT_MIN;

        for(int i = 0; i < vert; i++) {
            for(int j = 0; j < horiz; j++) {
                scanf(" %c", &grid[i][j]);
            }
        }

        pair<int, int> coord;
        scanf("%d %d", &coord.first, &coord.second);
        land = grid[coord.first][coord.second];
        dfs(coord, vert, horiz, land);
        
        for(int i = 0; i < vert; i++) {
            for(int j = 0; j < horiz; j++) {
                if(!seen[i][j] && grid[i][j] == land) {
                    counter = 0;
                    dfs({i, j}, vert, horiz, land);
                    if(counter > biggest) biggest = counter;
                }
            }
        } 

        biggest > 0 ? printf("%d\n", biggest) : printf("0\n");

    }

    return 0;
}
