
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
    int t;
    cin >> t;

    for (int a = 0; a < t; a++) {
        int r, c;
        cin >> r >> c;

        bool grid[r][c];
        vector<pair<int, int>> pts;
        int ans = 0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> grid[i][j];
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (!grid[i][j]) continue;

                if (j != 0 && i != 0 && grid[i - 1][j] == grid[i][j - 1] &&
                    grid[i - 1][j]) {
                    pts.push_back({i, j});
                    continue;
                }

                if (j != 0 && i != r - 1 && grid[i + 1][j] == grid[i][j - 1] &&
                    grid[i + 1][j]) {
                    pts.push_back({i, j});
                    continue;
                }

                if (j != c - 1 && i != 0 && grid[i - 1][j] == grid[i][j + 1] &&
                    grid[i - 1][j]) {
                    pts.push_back({i, j});
                    continue;
                }
                if (j != c - 1 && i != r - 1 &&
                    grid[i + 1][j] == grid[i][j + 1] && grid[i + 1][j]) {
                    pts.push_back({i, j});
                    continue;
                }
            }
        }

        for (const auto& pt : pts) {
            // Calculate vertical & horizontal segs
            int up = 0, down = 0, left = 0, right = 0;
            for (int i = 0; pt.first - i >= 0; i++) {
                if (grid[pt.first - i][pt.second])
                    up++;
                else
                    break;
            }

            for (int i = 0; pt.first + i < r; i++) {
                if (grid[pt.first + i][pt.second])
                    down++;
                else
                    break;
            }
            for (int i = 0; pt.second - i >= 0; i++) {
                if (grid[pt.first][pt.second - i])
                    left++;
                else
                    break;
            }
            for (int i = 0; pt.second + i < c; i++) {
                if (grid[pt.first][pt.second + i])
                    right++;
                else
                    break;
            }

            // cout << left << " " << right << " " << up << " " << down << endl;

            if (right >= 2) {
                if (up >= 2) {
                    if (2 * right <= up)
                        ans += right - 1;
                    else
                        ans += up / 2 - 1;
                }

                if (down >= 2) {
                    if (2 * right <= down)
                        ans += right - 1;
                    else
                        ans += down / 2 - 1;
                }
            }

            if (left >= 2) {
                if (up >= 2) {
                    if (2 * left <= up)
                        ans += left - 1;
                    else
                        ans += up / 2 - 1;
                }

                if (down >= 2) {
                    if (2 * left <= down)
                        ans += left - 1;
                    else
                        ans += down / 2 - 1;
                }
            }

            if (up >= 2) {
                if (right >= 2) {
                    if (2 * up <= right)
                        ans += up - 1;
                    else
                        ans += right / 2 - 1;
                }

                if (left >= 2) {
                    if (2 * up <= left)
                        ans += up - 1;
                    else
                        ans += left / 2 - 1;
                }
            }

            if (down >= 2) {
                if (right >= 2) {
                    if (2 * down <= right)
                        ans += down - 1;
                    else
                        ans += right / 2 - 1;
                }

                if (left >= 2) {
                    if (2 * down <= left)
                        ans += down - 1;
                    else
                        ans += left / 2 - 1;
                }
            }
        }

        cout << "Case #" << a + 1 << ": " << ans << endl;
    }

    return 0;
}
