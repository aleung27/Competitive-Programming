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

ll calc(int y, int x, int blockWidth, vector<vector<ll>>& grid) {
    ll sum = 0;

    for (int posX = x; posX > x - blockWidth; posX--) {
        sum += grid[y][posX];
    }

    return sum;
}

struct placement {
    ll value;
    int lastBlock;
};

int main() {
    FASTIO
    int h, w, blockWidth;
    ll next;
    cin >> h >> w >> blockWidth;

    vector<vector<ll>> grid;

    for (int i = 0; i < h; i++) {
        vector<ll> row;
        for (int j = 0; j < w; j++) {
            cin >> next;
            row.push_back(next);
        }
        grid.push_back(row);
    }

    static placement dp[50][50];
    for (int i = h - 1; i >= 0; i--) {
        for (int j = 0; j < w; j++) {
            // cout << i << "|" << j << endl;
            dp[i][j] = {INT_MIN, -1};
            if (j - blockWidth + 1 < 0) continue;

            ll sum = calc(i, j, blockWidth, grid);

            if (i == h - 1) {
                dp[i][j] = {sum, -1};
            } else {
                placement best = {INT_MIN, -1};

                for (int k = j - blockWidth + 1; k < min(w, j + blockWidth);
                     k++) {
                    if (k < 0) continue;
                    if (dp[i + 1][k].value + sum > best.value) {
                        best = {dp[i + 1][k].value + sum, k};
                    }
                }

                dp[i][j] = best;
            }
        }
    }

    // for (int i = 0; i < h; i++) {
    //     for (int j = 0; j < w; j++) {
    //         cout << dp[i][j].value << "|" << dp[i][j].lastBlock << " ";
    //     }
    //     cout << endl;
    // }

    placement best = {INT_MIN, -1};
    int prevBest;
    for (int j = 0; j < w; j++) {
        if (dp[0][j].value > best.value) {
            best = dp[0][j];
            prevBest = j;
        }
    }

    vector<vector<char>> output;
    int currentC = 0;
    while (1) {
        vector<char> row(w, '.');
        for (int i = prevBest; i > prevBest - blockWidth; i--) {
            row[i] = 'X';
        }
        output.push_back(row);

        prevBest = best.lastBlock;
        if (prevBest == -1) break;
        best = dp[++currentC][best.lastBlock];
    }

    for (const auto& s : output) {
        for (const auto& c : s) cout << c;
        cout << endl;
    }

    return 0;
}
