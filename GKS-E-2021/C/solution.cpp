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

struct query {
    int i, j;
    bool down;
};

int main() {
    FASTIO
    int t;
    cin >> t;

    for (int a = 1; a <= t; a++) {
        int n, m;
        int filled = 0;
        cin >> n >> m;

        char grid[n][m];
        queue<query> process;

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;

            for (int j = 0; j < s.length(); j++) {
                grid[i][j] = s[j];
                if (grid[i][j] != '#' && grid[i][j] != '.') {
                    process.push({i, j, false});
                    process.push({i, j, true});
                }
            }
        }

        while (!process.empty()) {
            auto at = process.front();
            process.pop();

            // cout << at.i << " " << at.j << endl;

            if (at.down) {
                // get the amount going down and going up;
                int below = 0, above = 0;
                for (int i = 1;
                     at.i + i <= n - 1 && grid[at.i + i][at.j] != '#'; i++)
                    below++;
                for (int i = 1; at.i - i >= 0 && grid[at.i - i][at.j] != '#';
                     i++)
                    above++;

                if (grid[at.i - above + below][at.j] != grid[at.i][at.j]) {
                    filled++;
                    grid[at.i - above + below][at.j] = grid[at.i][at.j];
                    process.push({at.i - above + below, at.j, false});
                }
            } else {
                // get the amount left and right
                int left = 0, right = 0;
                for (int j = 1;
                     at.j + j <= m - 1 && grid[at.i][at.j + j] != '#'; j++)
                    right++;
                for (int j = 1; at.j - j >= 0 && grid[at.i][at.j - j] != '#';
                     j++)
                    left++;

                if (grid[at.i][at.j - left + right] != grid[at.i][at.j]) {
                    filled++;
                    grid[at.i][at.j - left + right] = grid[at.i][at.j];
                    process.push({at.i, at.j - left + right, true});
                }
            }
        }

        cout << "Case #" << a << ": " << filled << endl;
        for (const auto& r : grid) {
            for (const auto& e : r) cout << e;
            cout << endl;
        }
    }

    return 0;
}
