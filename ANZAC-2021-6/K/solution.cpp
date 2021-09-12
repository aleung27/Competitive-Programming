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

map<char, int> Direction = {{'N', 3}, {'S', 2}, {'E', 0}, {'W', 1}};
map<pair<int, char>, int> RelativeDirections = {
    {{0, 'L'}, 3}, {{0, 'R'}, 2}, {{0, 'F'}, 0}, {{1, 'F'}, 1},
    {{1, 'L'}, 2}, {{1, 'R'}, 3}, {{2, 'L'}, 0}, {{2, 'R'}, 1},
    {{2, 'F'}, 2}, {{3, 'F'}, 3}, {{3, 'L'}, 1}, {{3, 'R'}, 0}};

struct Position {
    pair<int, int> coord;
    int from;
    int count;
};

int solve(map<pair<int, int>, vector<vector<char>>>& grid, pair<int, int> coord,
          pair<int, int>& goal, int from, int count) {
    queue<Position> q;
    bool state[10][10][4];
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            for (int k = 0; k < 4; k++) state[i][j][k] = false;
    q.push({coord, from, count});

    while (!q.empty()) {
        auto at = q.front();
        q.pop();

        if (state[at.coord.first][at.coord.second][at.from]) continue;
        if (at.coord.first == goal.first && at.coord.second == goal.second) {
            return at.count;
        }
        state[at.coord.first][at.coord.second][at.from] = true;

        // cout << at.coord.first << " " << at.coord.second << " " << at.from
        //      << endl;
        auto moves = grid[at.coord][at.from];
        for (const auto& e : moves) {
            int dir = RelativeDirections[{at.from, e}];
            pair<int, int> newCoord = {at.coord.first + dy[dir],
                                       at.coord.second + dx[dir]};

            if (!state[newCoord.first][newCoord.second][dir]) {
                // cout << "here" << endl;
                q.push({newCoord, dir, at.count + 1});
            }
        }
    }

    return -1;
}

int main() {
    FASTIO

    while (1) {
        string s, next;
        pair<int, int> start, goal, coord;
        char dir;

        cin >> s;
        if (s == "END") break;
        cin >> start.first >> start.second >> dir >> goal.first >> goal.second;

        map<pair<int, int>, vector<vector<char>>> grid;
        while (1) {
            cin >> coord.first;
            if (coord.first == 0) break;
            cin >> coord.second;

            grid.insert({coord, vector<vector<char>>(4, vector<char>())});

            while (1) {
                cin >> next;
                if (next == "*") break;

                int val = Direction[next[0]];
                for (int i = 1; i < next.length(); i++) {
                    grid[coord][val].push_back(next[i]);
                }
            }
        }

        // for (const auto& e : grid) {
        //     cout << e.first.first << " " << e.first.second << endl;
        //     for (const auto& f : e.second) {
        //         for (const auto& g : f) {
        //             cout << g << " ";
        //         }
        //         cout << endl;
        //     }
        // }

        int ans = solve(grid,
                        {start.first + dy[Direction[dir]],
                         start.second + dx[Direction[dir]]},
                        goal, Direction[dir], 1);

        cout << s << endl;
        if (ans == -1)
            cout << "No Solution Possible" << endl;
        else
            cout << "Solved in " << ans << " steps" << endl;
    }

    return 0;
}
