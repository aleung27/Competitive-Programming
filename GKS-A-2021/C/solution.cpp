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

struct pt {
    int height;
    int yi, xj;
};

int r, c;
int grid[305][305] = {0};
ll ans = 0;

bool comp(const pt& a, const pt& b) {
    if (a.height != b.height) return a.height > b.height;
    if (a.yi != b.yi) return a.yi < b.yi;
    if (a.xj != b.xj) return a.xj < b.xj;
    return false;
}

void solve(pt at) {
    if (at.height == 0) return;

    for (int i = 0; i < 4; i++) {
        if (at.yi + dy[i] < 0 || at.yi + dy[i] >= r || at.xj + dx[i] < 0 ||
            at.xj + dx[i] >= c)
            continue;

        if (grid[at.yi][at.xj] - grid[at.yi + dy[i]][at.xj + dx[i]] > 1) {
            ans +=
                (grid[at.yi][at.xj] - 1) - grid[at.yi + dy[i]][at.xj + dx[i]];
            grid[at.yi + dy[i]][at.xj + dx[i]] = grid[at.yi][at.xj] - 1;
            solve({grid[at.yi + dy[i]][at.xj + dx[i]], at.yi + dy[i],
                   at.xj + dx[i]});
        }
    }
}

int main() {
    FASTIO
    int t;
    cin >> t;

    for (int a = 0; a < t; a++) {
        cin >> r >> c;
        ans = 0;
        vector<pt> points;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> grid[i][j];
                points.push_back({grid[i][j], i, j});
            }
        }

        sort(points.begin(), points.end(), comp);

        for (const auto& at : points) {
            if (at.height == 0) break;
            if (at.height == grid[at.yi][at.xj]) solve(at);
        }

        cout << "Case #" << a + 1 << ": " << ans << endl;
    }

    return 0;
}
