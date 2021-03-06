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

bool sieve[10000002] = {false};

int main() {
    int n;

    for (int i = 2; i < sqrt(10000001); i++) {
        if (sieve[i]) continue;
        for (int j = 2 * i; j < 10000001; j += i) {
            sieve[j] = true;
        }
    }

    while (scanf("%d", &n) == 1) {
        if (n < 8) {
            printf("Impossible.\n");
            continue;
        }

        bool odd = false;
        if (n % 2 == 1) {
            odd = true;
            n -= 5;
        } else {
            n -= 4;
        }

        for (int i = 2; i < 10000001; i++) {
            if (!sieve[i] && !sieve[n - i]) {
                odd ? printf("%d %d 2 3\n", i, n - i)
                    : printf("%d %d 2 2\n", i, n - i);
                break;
            }
        }
    }

    return 0;
}
