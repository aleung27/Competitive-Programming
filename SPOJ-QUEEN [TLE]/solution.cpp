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

pair<int, int> start, finish;
int r, c;

void bfs(pair<int, int> at, vector<vector<char>>& grid,
         vector<vector<pair<int, int>>>& seen) {
    seen[at.first][at.second] = {0, -1};
    queue<pair<int, int>> q;
    q.push(at);

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        if (curr == finish) break;

        for (int i = 0; i < 8; i++) {
            for (int j = 1;; j++) {
                int newR = curr.first + j * dy[i];
                int newC = curr.second + j * dx[i];

                if (newR >= r || newR < 0 || newC >= c || newC < 0 ||
                    grid[newR][newC] == 'X') {
                    break;
                }

                if (seen[newR][newC] == make_pair(-1, -1)) {
                    seen[newR][newC] = {seen[curr.first][curr.second].first, i};
                    if (i != seen[curr.first][curr.second].second)
                        seen[newR][newC].first++;

                    q.push({newR, newC});
                } else if (seen[newR][newC].second == i) {
                    break;
                } else {
                    seen[newR][newC].second = i;
                    continue;
                }
            }
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &r, &c);

        vector<vector<char>> grid;
        vector<vector<pair<int, int>>> seen;

        for (int i = 0; i < r; i++) {
            vector<char> row;
            vector<pair<int, int>> rowSeen;
            char next;

            for (int j = 0; j < c; j++) {
                scanf(" %c", &next);
                row.push_back(next);
                rowSeen.push_back({-1, -1});
                if (next == 'S') start = {i, j};
                if (next == 'F') finish = {i, j};
            }

            grid.push_back(row);
            seen.push_back(rowSeen);
        }

        bfs(start, grid, seen);
        printf("%d\n", seen[finish.first][finish.second].first);
    }

    return 0;
}
