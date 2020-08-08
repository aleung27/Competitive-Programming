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
T modpow(T x, T n, T m) {
    if (n == 0) return 1 % m;
    ll u = modpow(x, n / 2, m);
    u = (u * u) % m;
    if (n % 2 == 1) u = (u * x) % m;
    return u;
}

char grid[31][81];
bool seen[31][81];

void bfs(pair<int, int> at, char wall) {
    queue<pair<int, int>> q;
    q.push(at);

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        grid[curr.first][curr.second] = '#';
        seen[curr.first][curr.second] = true;

        for (int i = 0; i < 4; i++) {
            if (curr.first + dy[i] < 0 || curr.first + dy[i] >= 79 ||
                curr.second + dx[i] < 0 || curr.second + dx[i] >= 79)
                continue;
            if (!seen[curr.first + dy[i]][curr.second + dx[i]] &&
                grid[curr.first + dy[i]][curr.second + dx[i]] != wall &&
                grid[curr.first + dy[i]][curr.second + dx[i]] != '_') {
                seen[curr.first + dy[i]][curr.second + dx[i]] = true;
                q.push({curr.first + dy[i], curr.second + dx[i]});
            }
        }
    }
}

int main() {
    FASTIO;
    int t;
    cin >> t;

    while (t--) {
        memset(grid, '_', 31 * 81);
        memset(seen, false, sizeof(bool) * 31 * 81);
        string s, lineBreak;
        pair<int, int> start;
        char wall;

        int i = 0;
        while (getline(cin, s)) {
            if (s[0] == '_') {
                lineBreak = s;
                break;
            }

            for (int j = 0; j < s.length(); j++) {
                grid[i][j] = s[j];
                if (s[j] == '*') {
                    start.first = i;
                    start.second = j;
                } else if (s[j] != ' ') {
                    wall = s[j];
                }
            }

            i++;
        }

        bfs(start, wall);

        for (int j = 0; j < i; j++) {
            bool shouldPrint = false;
            for (int k = 0; k < 80; k++) {
                if (grid[j][k] == '_') break;
                cout << grid[j][k];
                shouldPrint = true;
            }
            if (shouldPrint) cout << endl;
        }

        cout << lineBreak << endl;
    }

    return 0;
}
