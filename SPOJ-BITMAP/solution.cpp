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

bool grid[185][185] = {false};
int dist[185][185] = {-1};

void bfs(queue<pair<int, int>>& q, int& r, int& c) {
    while (!q.empty()) {
        pair<int, int> at = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            if (at.first + dy[i] < 0 || at.first + dy[i] >= r ||
                at.second + dx[i] < 0 || at.second + dx[i] >= c)
                continue;

            if (dist[at.first + dy[i]][at.second + dx[i]] == -1) {
                dist[at.first + dy[i]][at.second + dx[i]] =
                    dist[at.first][at.second] + 1;
                q.push({at.first + dy[i], at.second + dx[i]});
            }
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int r, c;
        char a;
        queue<pair<int, int>> q;
        scanf("%d %d", &r, &c);
        memset(grid, false, 185 * 185 * sizeof(bool));
        memset(dist, -1, 185 * 185 * sizeof(int));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                scanf(" %c", &a);
                (a - '0') ? grid[i][j] = true : grid[i][j] = false;
                if (a - '0') {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        bfs(q, r, c);

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                j == c - 1 ? printf("%d", dist[i][j])
                           : printf("%d ", dist[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
