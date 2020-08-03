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
    bool grid[1001][1001]; //[x][y]
    memset(grid, false, 1001*1001*sizeof(bool));

    int n, x, y;
    scanf("%d", &n);
    while(n--) {
        scanf("%d %d", &x, &y);
        grid[x][y] = true;
    }

    ll ans = 0;

    // L and T border SE diag
    for(int i = 1; i < 1001; i++) {
        x = i;
        y = 1;
        int count = 0;
        
        while(x < 1001 && y < 1001) {
            if(grid[x][y]) count++;
            x++;
            y++;
        }

        ans += count*(count-1)/2;

        count = 0;
        x = 1;
        y = i;
        if(i != 1){
            while(x < 1001 && y < 1001) {
                if(grid[x][y]) count++;
                x++;
                y++;
            }
        }

        ans += count*(count-1)/2;
    }

    for(int i = 1; i < 1001; i++) {
        x = i;
        y = 1;
        int count = 0;

        while(x > 0 && y < 1001) {
            if(grid[x][y]) count++;
            x--;
            y++;
        }

        ans += count*(count-1)/2;

        count = 0;
        x = 1000;
        y = i;
        if(i != 1) {
            while(x > 0 && y < 1001) {
                if(grid[x][y]) count++;
                x--;
                y++;
            }
        }
        ans += count*(count-1)/2;
    }

    printf("%lld\n", ans);
    return 0;
}
