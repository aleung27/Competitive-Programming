#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define X real()
#define Y imag()
#define EPS 0.000000001
#define M_PI 3.14159265358979323846
#define CROSSPROD(a, b) (conj(a)*(b)).Y
#define DOTPROD(a, b) ((a).X*(b).X + (a).Y+(b).Y)
#define FASTIO ios::sync_with_stdio(false);

int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};

template <class T>
T gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

template <class T>
T modpow(T x, T n, T m) {
    if(n == 0) return 1 % m;
    ll u = modpow(x, n/2, m);
    u = (u*u)%m;
    if(n%2 == 1) u = (u*x)%m;
    return u;
}

char grid[55][55];
bool seen[55][55];
bool cycle = false;

void dfs(pair<int, int>at, pair<int, int>from, int& h, int& w) {
    seen[at.first][at.second] = true;

    for(int i = 0; i < 4; i++) {
        if(at.first + dy[i] < 0 || at.first + dy[i] >= h || at.second + dx[i] < 0 || at.second + dx[i] >= w) continue;
        pair<int, int> temp(at.first + dy[i], at.second + dx[i]);
        if(!seen[temp.first][temp.second] && grid[temp.first][temp.second] == grid[at.first][at.second]) dfs(temp, at, h, w);
        else if(seen[temp.first][temp.second] && temp != from && grid[temp.first][temp.second] == grid[at.first][at.second]) cycle = true;
    }
}

int main () {
    int h, w;
    memset(seen, false, 55*55*sizeof(bool));
    scanf("%d %d", &h, &w);

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            scanf(" %c", &grid[i][j]);
        }
    }

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(!seen[i][j]) {
                dfs({i,j}, {-1, -1}, h, w);
                
                if(cycle) {
                    printf("Yes\n");
                    return 0;
                }
            }
        }
    }

    printf("No\n");

    return 0;
}
