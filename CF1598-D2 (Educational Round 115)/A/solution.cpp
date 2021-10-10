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

void dfs(int x, int y, vector<vector<bool>>& grid, vector<vector<bool>>& seen) {
    seen[y][x] = true;

    for (int i = 0; i < 8; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (newY < 0 || newY >= 2 || newX < 0 || newX >= grid[0].size())
            continue;
        if (!seen[newY][newX] && !grid[newY][newX]) {
            seen[newY][newX] = true;
            dfs(newX, newY, grid, seen);
        }
    }
}

int main() {
    FASTIO
    int t;
    cin >> t;

    while (t--) {
        int n;
        char c;
        cin >> n;

        vector<vector<bool>> grid(2, vector<bool>(n, false));
        vector<vector<bool>> seen(2, vector<bool>(n, false));

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                cin >> c;
                if (c == '0')
                    grid[i][j] = false;
                else
                    grid[i][j] = true;
            }
        }

        dfs(0, 0, grid, seen);

        if (seen[1][n - 1])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
