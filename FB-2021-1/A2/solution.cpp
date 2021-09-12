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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t, n;
    char next;
    cin >> t;

    for (int a = 1; a <= t; a++) {
        cin >> n;

        string s = "";
        ll ans = 0;
        pair<int, int> last[n];
        int lastx = -1, lasto = -1;

        for (int i = 0; i < n; i++) {
            cin >> next;
            s += next;
            last[i] = {lastx, lasto};

            if (next == 'X')
                lastx = i;
            else if (next == 'O')
                lasto = i;

            // cout << last[i].first << " " << last[i].second << endl;
        }

        vector<int> dp(n, 0);
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == 'F')
                dp[i] = dp[i - 1];
            else if (s[i] == 'X') {
                if (max(last[i].first, last[i].second) == last[i].first)
                    dp[i] = dp[i - 1];
                else
                    dp[i] = dp[i - 1] + last[i].second + 1;
            } else if (s[i] == 'O') {
                if (max(last[i].first, last[i].second) == last[i].second)
                    dp[i] = dp[i - 1];
                else
                    dp[i] = dp[i - 1] + last[i].first + 1;
            }

            dp[i] = dp[i] % 1000000007;
            ans = (ans + dp[i]) % 1000000007;
        }

        cout << "Case #" << a << ": " << ans << endl;
    }
    return 0;
}
