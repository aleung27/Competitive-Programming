#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define X real()
#define Y imag()
#define EPS 0.000000001
#define M_PI 3.14159265358979323846
#define CROSSPROD(a, b) (conj(a) * (b)).Y
#define DOTPROD(a, b) ((a).X * (b).X + (a).Y + (b).Y)
#define FASTIO ios::sync_with_stdio(false);

int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};

template <class T>
T gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

template <class T>
T modpow(T x, T n, T m) {
    if (n == 0) return 1 % m;
    ll u = modpow(x, n / 2, m);
    u = (u * u) % m;
    if (n % 2 == 1) u = (u * x) % m;
    return u;
}

int main() {
    int n;
    scanf("%d", &n);

    if (n % 2 == 0) {
        printf("-1\n");
    } else {
        for (int i = 0; i < n; i++) {
            i == n - 1 ? printf("%d\n", i) : printf("%d ", i);
        }
        for (int i = 1; i < n + 1; i++) {
            i == n ? printf("%d\n", i % n) : printf("%d ", i % n);
        }

        int i = 1;
        for (int j = 0; j < n; j++) {
            j == n - 1 ? printf("%d\n", i % n) : printf("%d ", i % n);
            i += 2;
        }
    }

    return 0;
}
