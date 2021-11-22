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

ll triangular(ll n) { return (n * (n + 1)) / 2; }

ll val(ll n, ll k) {
    if (n <= k)
        return triangular(n);
    else
        return 2 * triangular(k) - k - triangular(2 * k - 1 - n);
}

int main() {
    FASTIO
    int t;
    cin >> t;

    while (t--) {
        ll k, x;
        cin >> k >> x;

        ll left = 1, right = 2 * k - 1;
        while (left <= right) {
            ll mid = (left + right) / 2;
            if (val(mid, k) >= x) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        if (left > 2 * k - 1)
            cout << right << endl;
        else
            cout << left << endl;
    }

    return 0;
}
