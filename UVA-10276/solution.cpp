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
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);
        int pegs[n];
        memset(pegs, 0, n * sizeof(int));

        int i = 1;
        for (;; i++) {
            bool found = false;

            for (int j = 0; j < n; j++) {
                if ((int)sqrt(pegs[j] + i) * (int)sqrt(pegs[j] + i) ==
                        pegs[j] + i ||
                    pegs[j] == 0) {
                    pegs[j] = i;
                    found = true;
                    break;
                }
            }

            if (!found) break;
        }

        printf("%d\n", i - 1);
    }

    return 0;
}
