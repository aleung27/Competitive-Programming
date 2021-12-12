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

ll sq(ll a) { return a * a; }

ll dp[205][205];

int main() {
    FASTIO
    int n, buckets;
    cin >> n >> buckets;

    fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(dp[0][0]), LLONG_MAX);

    vector<ll> sizes;
    for (int i = 0; i < n; i++) {
        ll next;
        cin >> next;
        sizes.push_back(next);
    }

    sort(sizes.begin(), sizes.end());

    if (buckets >= n) {
        cout << "0" << endl;
        return 0;
    } else if (buckets == 1) {
        cout << (sizes.back() - sizes.front()) * (sizes.back() - sizes.front())
             << endl;
        return 0;
    }

    for (int i = 1; i <= buckets; i++) {
        for (int j = sizes.size() - i; j >= 0; j--) {
            // cout << i << " " << j << endl;
            if (j == sizes.size() - i)
                dp[i][j] = 0;
            else {
                if (i == 1) {
                    dp[i][j] = sq(sizes.back() - sizes[j]);
                } else {
                    for (int k = j + 1; k <= sizes.size() - i + 1; k++) {
                        dp[i][j] =
                            min(dp[i][j],
                                dp[i - 1][k] + sq(sizes[k - 1] - sizes[j]));
                    }
                }
            }
        }
    }

    cout << dp[buckets][0] << endl;

    return 0;
}
