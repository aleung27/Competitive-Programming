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
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        ll dp[2][s.length()];

        dp[0][0] = 1;
        dp[1][0] = 1;
        if (s[0] == '0') dp[1][0] = LLONG_MIN;
        if (s[0] == '1') dp[0][0] = LLONG_MIN;

        for (int i = 1; i < s.length(); i++) {
            if (s[i] == '?') {
                dp[0][i] = max((ll)1, dp[1][i - 1] + 1);
                dp[1][i] = max((ll)1, dp[0][i - 1] + 1);
            } else if (s[i] == '0') {
                dp[1][i] = LLONG_MIN;
                dp[0][i] = max((ll)1, dp[1][i - 1] + 1);
            } else if (s[i] == '1') {
                dp[0][i] = LLONG_MIN;
                dp[1][i] = max((ll)1, dp[0][i - 1] + 1);
            }
        }

        ll total = 0;
        for (int i = 0; i < s.length(); i++) {
            total += max(dp[0][i], dp[1][i]);
        }

        cout << total << endl;
    }

    return 0;
}
