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

double vals[5] = {1.000000, 1.500000, 1.833333, 2.083333, 2.283333};

double harmonic(double n) {
    return log(n) + 0.5772156649 + 1 / (2 * n) - 1 / (12 * n * n) +
           1 / (120 * n * n * n * n) - 1 / (252 * pow(n, 6)) +
           1 / (240 * pow(n, 8));
}

int main() {
    FASTIO
    cout << fixed << showpoint << setprecision(8);
    int t;
    cin >> t;

    for (int a = 1; a <= t; a++) {
        ll n;
        cin >> n;
        double ans = n <= 5 ? vals[n - 1] : harmonic(n);
        cout << "Case #" << a << ": " << ans << endl;
    }

    return 0;
}
