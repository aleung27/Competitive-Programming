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

double distance(double apart, double m) {
    return sqrt(2 - 2 * cos(2 * M_PI * apart / m));
}

int main() {
    FASTIO
    int n, m, next;
    cin >> n;

    vector<int> program;
    map<int, int> map;  // map node # to type #

    for (int i = 0; i < n; i++) {
        cin >> next;
        program.push_back(next);
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> next;
        map.insert({i, next});
    }

    // First index is vertex number
    // second index is exercise number
    double dp[m][n];
    for (int i = 0; i < n; i++) {
        // i -> exercise number
        if (!i) {
            for (int j = 0; j < m; j++) {
                if (map[j] == program[i])
                    dp[j][0] = 1;
                else
                    dp[j][0] = 100000;
            }
            continue;
        }

        // j -> vertex number
        for (int j = 0; j < m; j++) {
            if (map[j] != program[i])
                dp[j][i] = 100000;
            else {
                dp[j][i] = 100000;

                for (int k = 0; k < m; k++) {
                    dp[j][i] =
                        min(dp[k][i - 1] + distance(abs(k - j), m), dp[j][i]);
                }
            }
        }
    }

    double ans = DBL_MAX;
    for (int i = 0; i < m; i++) {
        ans = min(ans, dp[i][n - 1]);
    }
    // for (int i = 0; i < m; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << fixed << setprecision(7) << ans << endl;
    return 0;
}
