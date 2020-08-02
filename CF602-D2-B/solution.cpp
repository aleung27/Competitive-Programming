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
    int n, a;
    scanf("%d", &n);

    vector<int> vals;
    int table[2][n];
    table[0][0] = table[1][0] = 1;
    int max = 1;

    for(int i = 0; i < n; i++) {
        scanf("%d", &a);
        vals.push_back(a);

        if(i > 0) {
            if(vals[i] > vals[i-1]) {
                table[0][i] = table[1][i-1]+1;
                table[1][i] = 1;
            } else if (vals[i] < vals[i-1]) {
                table[0][i] = 1;
                table[1][i] = table[0][i-1] + 1;
            } else {
                table[0][i] = table[0][i-1] + 1;
                table[1][i] = table[1][i-1] + 1;
            }

            if(table[0][i] > max) max = table[0][i];
            else if(table[1][i] > max) max = table[1][i];
        }
    }

    printf("%d\n", max);

    return 0;
}
