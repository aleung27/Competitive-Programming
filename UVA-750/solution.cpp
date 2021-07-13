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

int counter = 1;
set<vector<pair<int, int>>> layouts;
set<vector<pair<int, int>>> seen;

bool comp(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
}

vector<pair<int, int>> mark(vector<vector<bool>>& grid, pair<int, int> pos) {
    vector<pair<int, int>> marks;

    for (int i = 0; i < 8; i++) {
        if (!grid[pos.first][i]) marks.push_back({pos.first, i});
        grid[pos.first][i] = true;
        if (!grid[i][pos.second]) marks.push_back({i, pos.second});
        grid[i][pos.second] = true;

        if (pos.first + i < 8 && pos.second + i < 8 &&
            !grid[pos.first + i][pos.second + i]) {
            grid[pos.first + i][pos.second + i] = true;
            marks.push_back({pos.first + i, pos.second + i});
        }
        if (pos.first - i >= 0 && pos.second - i >= 0 &&
            !grid[pos.first - i][pos.second - i]) {
            grid[pos.first - i][pos.second - i] = true;
            marks.push_back({pos.first - i, pos.second - i});
        }
        if (pos.first + i < 8 && pos.second - i >= 0 &&
            !grid[pos.first + i][pos.second - i]) {
            grid[pos.first + i][pos.second - i] = true;
            marks.push_back({pos.first + i, pos.second - i});
        }
        if (pos.first - i >= 0 && pos.second + i < 8 &&
            !grid[pos.first - i][pos.second + i]) {
            grid[pos.first - i][pos.second + i] = true;
            marks.push_back({pos.first - i, pos.second + i});
        }
    }

    return marks;
}

void unmark(vector<vector<bool>>& grid, vector<pair<int, int>> marks) {
    for (const auto& e : marks) grid[e.first][e.second] = false;
}
void solve(vector<vector<bool>> grid, vector<pair<int, int>> queens, int qNum) {
    vector<pair<int, int>> copy = queens;
    sort(copy.begin(), copy.end(), comp);
    if (seen.count(copy)) return;
    seen.insert(copy);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (!grid[i][j]) {
                if (qNum == 8) {
                    queens.push_back({i, j});
                    vector<pair<int, int>> copy = queens;
                    sort(copy.begin(), copy.end(), comp);
                    layouts.insert(copy);
                    queens.pop_back();
                } else {
                    vector<pair<int, int>> marks = mark(grid, {i, j});
                    queens.push_back({i, j});
                    solve(grid, queens, qNum + 1);
                    queens.pop_back();
                    unmark(grid, marks);
                }
            }
        }
    }
}

int main() {
    FASTIO
    int t;
    cin >> t;

    while (t--) {
        counter = 1;
        layouts.clear();
        seen.clear();
        vector<pair<int, int>> queens;
        pair<int, int> given;
        vector<vector<bool>> grid(8, vector<bool>(8, false));

        cin >> given.first >> given.second;
        given.first--;
        given.second--;

        queens.push_back(given);
        mark(grid, queens[0]);

        cout << "SOLN       COLUMN" << endl;
        cout << " #      1 2 3 4 5 6 7 8" << endl << endl;
        solve(grid, queens, 2);

        for (const auto& e : layouts) {
            if (counter < 10) cout << " ";
            cout << counter++ << "      ";
            for (int i = 0; i < e.size(); i++) {
                i == e.size() - 1 ? cout << e[i].first + 1 << endl
                                  : cout << e[i].first + 1 << " ";
            }
        }
        if (t) cout << endl;
    }
    return 0;
}
