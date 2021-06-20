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

int main() {
    FASTIO
    int n, q;
    string s;
    cin >> n >> q >> s;

    // Extra characters from substring [0:i]
    ll extra[n];
    for (int i = 0; i < n; i++) {
        if (i) {
            extra[i] = extra[i - 1] + s[i] - 'a';
        } else {
            extra[i] = s[i] - 'a';
        }
        // cout << extra[i] << " ";
    }
    // cout << endl;

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        ll ans =
            l == 0 ? extra[r] + r - l + 1 : extra[r] - extra[l - 1] + r - l + 1;
        cout << ans << endl;
    }

    return 0;
}
