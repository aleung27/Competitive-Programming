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

map<pair<ull, ull>, ull> vals;

ull ncr(ull n, ull r) {
    if (n == r) {
        vals.insert({{n, r}, 1});
        return 1;
    }

    if (r == 0) {
        vals.insert({{n, r}, 1});
        return 1;
    }

    if (vals.count({n - 1, r - 1}) && vals.count({n - 1, r})) {
    } else if (vals.count({n - 1, r - 1})) {
        vals.insert({{n - 1, r}, ncr(n - 1, r)});
    } else if (vals.count({n - 1, r})) {
        vals.insert({{n - 1, r - 1}, ncr(n - 1, r - 1)});
    } else {
        vals.insert({{n - 1, r}, ncr(n - 1, r)});
        vals.insert({{n - 1, r - 1}, ncr(n - 1, r - 1)});
    }

    return vals[{n - 1, r - 1}] + vals[{n - 1, r}];
}

int main() {
    ull n, m, t;
    cin >> n >> m >> t;

    ull total = ncr(n + m, t);
    if (m >= t - 1) {
        total -= ncr(n, 3) * ncr(m, t - 3) + ncr(n, 2) * ncr(m, t - 2) +
                 ncr(n, 1) * ncr(m, t - 1);
    } else if (m >= t - 2) {
        total -= ncr(n, 3) * ncr(m, t - 3) + ncr(n, 2) * ncr(m, t - 2);
    } else if (m >= t - 3) {
        total -= ncr(n, 3) * ncr(m, t - 3);
    }

    if (n >= t) {
        total -= ncr(n, t);
    }

    if (m >= t) {
        total -= ncr(m, t);
    }

    cout << total << endl;

    return 0;
}
