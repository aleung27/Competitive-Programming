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

int bfs(vector<vector<vector<int>>>& steep, int x, int y, int width, int height,
        int s) {
    queue<pair<int, int>> q;
    set<pair<int, int>> seen;
    seen.insert({x, y});
    q.push({x, y});
    int counter = 1;

    while (!q.empty()) {
        auto at = q.front();
        // cout << at.first << " " << at.second << endl;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int newX = at.first + dx[i], newY = at.second + dy[i];
            if (newX < 0 || newX >= width || newY < 0 || newY >= height)
                continue;
            if (seen.count({newX, newY}) || steep[at.second][at.first][i] > s)
                continue;

            seen.insert({newX, newY});
            q.push({newX, newY});
            counter++;
        }
    }

    return counter;
}

int main() {
    FASTIO
    int height, width, q;
    cin >> height >> width >> q;

    vector<vector<int>> grid(height, vector<int>(width));
    vector<vector<vector<int>>> steep(
        height, vector<vector<int>>(width, vector<int>(4, 305)));

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < 4; k++) {
                if (i + dy[k] >= height || i + dy[k] < 0 ||
                    j + dx[k] >= width || j + dx[k] < 0)
                    continue;

                steep[i][j][k] = abs(grid[i][j] - grid[i + dy[k]][j + dx[k]]);
            }
            // cout << steep[i][j][0] << " " << steep[i][j][1] << " "
            //      << steep[i][j][2] << " " << steep[i][j][3] << " " << endl;
        }
    }

    int x, y, s;
    for (int i = 0; i < q; i++) {
        cin >> x >> y >> s;
        x--;
        y--;

        cout << bfs(steep, x, y, width, height, s) << endl;
    }

    return 0;
}
