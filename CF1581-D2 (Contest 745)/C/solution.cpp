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
// TODO: Incomplete
struct cell {
    int val, optR, optC;
};

// Return the cost + if more - if less of swapping old col to new col
int colswap(int oldCol, int newCol, int start, int end,
            vector<vector<bool>>& grid) {
    int oldCost = 0, newCost = 0;

    for (int i = start + 1; i <= end - 1; i++) {
        newCost += !grid[i][newCol];
        oldCost += !grid[i][oldCol];
    }

    return (newCost - oldCost);
}

int rowswap(int oldRow, int newRow, int start, int end,
            vector<vector<bool>>& grid) {
    int oldCost = 0, newCost = 0;

    for (int j = start + 1; j <= end - 1; j++) {
        newCost += !grid[newRow][j];
        oldCost += !grid[oldRow][j];
    }

    return (newCost - oldCost);
}

int main() {
    FASTIO
    int t;
    cin >> t;

    while (t--) {
        int rows, cols;
        string s;
        cin >> rows >> cols;

        vector<vector<bool>> grid(rows, vector<bool>(cols, false));
        vector<vector<cell>> dp(rows, vector<cell>(cols, {10000000, 0, 0}));

        for (int i = 0; i < rows; i++) {
            cin >> s;
            for (int j = 0; j < s.length(); j++) {
                grid[i][j] = (s[j] == '1');
            }
        }

        // Fill in the first square
        dp[4][3].val = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 4; j++) {
                if (i == 0 && j >= 1 && j <= 2) {
                    if (!grid[i][j]) dp[4][3].val++;
                } else if (j == 0 && i >= 1 && i <= 3) {
                    if (!grid[i][j]) dp[4][3].val++;
                } else if (j == 3 && i >= 1 && i <= 3) {
                    if (!grid[i][j]) dp[4][3].val++;
                } else if (i == 4 && j >= 1 && j <= 2) {
                    if (!grid[i][j]) dp[4][3].val++;
                } else if (i >= 1 && i <= 3 && j >= 1 && j <= 2) {
                    if (grid[i][j]) dp[4][3].val++;
                }
            }
        }

        int ans = dp[4][3].val;
        for (int i = 4; i < rows; i++) {
            for (int j = 3; j < cols; j++) {
                if (i == 4 && j == 3) continue;

                // Move down
                cell down;
                int downShift = rowswap(dp[i - 1][j].optR, i - 4,
                                        dp[i - 1][j].optC, j, grid);
                down.val = dp[i - 1][j].val +
                           rowswap(i - 1, i, dp[i - 1][j].optC, j, grid);
                down.optR = dp[i - 1][j].optR;
                down.optC = dp[i - 1][j].optC;
                if (downShift <= 0) {
                    down.val += downShift;
                    down.optR = i - 4;
                }

                // Move Across
                cell across;
                int acrossShift = colswap(dp[i][j - 1].optC, j - 3,
                                          dp[i][j - 1].optR, i, grid);
                across.val = dp[i][j - 1].val +
                             colswap(j - 1, j, dp[i][j - 1].optR, i, grid);
                across.optR = dp[i][j - 1].optR;
                across.optC = dp[i][j - 1].optC;
                if (acrossShift <= 0) {
                    across.val += acrossShift;
                    down.optC = j - 3;
                }

                cout << across.val << " " << down.val << endl;
                dp[i][j] = across.val < down.val ? across : down;
                ans = min(ans, dp[i][j].val);
            }
        }

        cout << ans << endl;
    }

    return 0;
}
