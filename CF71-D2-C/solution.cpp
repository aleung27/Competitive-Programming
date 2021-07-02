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
T lcm(T a, T b) {
    return a * b / gcd<T>(a, b);
}

template <class T>
T modpow(T x, T n, T m) {
    if (n == 0) return 1 % m;
    ll u = modpow(x, n / 2, m);
    u = (u * u) % m;
    if (n % 2 == 1) u = (u * x) % m;
    return u;
}

set<int> pf(int n) {
    set<int> factors;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors.insert(i);
            n /= i;
        }
    }
    if (n > 1) factors.insert(n);

    return factors;
}

int main() {
    FASTIO
    int n;
    cin >> n;
    bool mood[n];

    for (int i = 0; i < n; i++) cin >> mood[i];

    set<int> factors = pf(n);
    if (n % 4 == 0) factors.insert(4);

    for (const auto& e : factors) {
        if (e == 2) continue;

        for (int i = 0; i < n / e; i++) {
            bool ok = true;
            for (int j = 0; j < e; j++) {
                if (!mood[(n / e) * j + i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}