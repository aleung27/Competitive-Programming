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
        int n;
        cin >> n;

        int arr[2 * n + 1], a[n], b[n];
        arr[0] = 10000;

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        for (int i = 0; i < n; i++) {
            arr[a[i]] = i;
            arr[b[i]] = i;
        }

        int dp[2 * n + 1];
        int ans = INT_MAX;
        for (int i = 2 * n - 1; i > 0; i -= 2) {
            if (i == 2 * n - 1)
                dp[i] = arr[i] + arr[i + 1];
            else {
                dp[i] =
                    min(dp[i + 2] + arr[i] - arr[i + 2], arr[i] + arr[i + 1]);
            }
            ans = min(ans, dp[i]);
        }

        cout << ans << endl;
    }

    return 0;
}
