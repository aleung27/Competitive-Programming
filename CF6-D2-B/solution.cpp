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

template <class T>
T gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main () {
    int dx[] = {1, -1, 0 ,0};
    int dy[] = {0, 0 ,1, -1};
    int n, m;
    char pres;

    scanf("%d %d %c", &n, &m, &pres);
    char grid[n][m];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf(" %c", &grid[i][j]);
        }
    }

    unordered_set<char> desks;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == pres) {
                for(int k = 0; k < 4; k++) {
                    if(i+dy[k] < 0 || i+dy[k] >= n || j+dx[k] < 0 || j+dx[k] >= m) continue;
                    if(grid[i+dy[k]][j+dx[k]] != '.' && grid[i+dy[k]][j+dx[k]] != pres) {
                       if(!desks.count(grid[i+dy[k]][j+dx[k]])) desks.insert(grid[i+dy[k]][j+dx[k]]); 
                    }
                }
            }
        }
    }

    printf("%d\n", (int)desks.size());

    return 0;
}
