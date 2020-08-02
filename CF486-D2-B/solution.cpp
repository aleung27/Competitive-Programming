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

int main () {
    int h, w, a;
    scanf("%d %d", &h, &w);

    bool grid [105][105];
    bool input [105][105];

    memset(grid, true, 105*105);

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            scanf("%d", &a);
            a ? input[i][j] = true : input[i][j] = false;
            if(!input[i][j]) {
                for(int k = 0; k < h; k++) {
                    grid[k][j] = false;
                }
                for(int k = 0; k < w; k++) {
                    grid[i][k] = false;
                }
            }
        }
    }    
    
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            bool seen = false;
            for(int k = 0; k < h; k++) {
                if(grid[k][j]) seen = true;
            }
            for(int k = 0; k < w; k++) {
                if(grid[i][k]) seen = true;
            }

            if((seen && !input[i][j]) || (!seen && input[i][j])) {
                printf("NO\n");
                return 0;
            }
        }
    }

    printf("YES\n");
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            j == w-1 ? printf("%d", grid[i][j]) : printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}
