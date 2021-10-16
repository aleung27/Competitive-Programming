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

int h, w;

bool place(int y, int x, int rugW, int rugH, vector<vector<char>>& grid) {
    if (y + rugH > h || x + rugW > w) return false;

    for (int i = y; i < y + rugH; i++) {
        for (int j = x; j < x + rugW; j++) {
            if (grid[i][j] == 'A') {
                return false;
            }
        }
    }

    return true;
}

int main() {
    FASTIO
    int rugW, rugH;
    string s;
    cin >> h >> w >> rugW >> rugH;

    vector<vector<char>> grid;
    for (int i = 0; i < h; i++) {
        cin >> s;
        vector<char> row;

        for (const auto& c : s) row.push_back(c);

        grid.push_back(row);
    }

    int counter = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (place(i, j, rugW, rugH, grid)) counter++;
            if (rugW != rugH && place(i, j, rugH, rugW, grid)) counter++;
        }
    }

    cout << counter << endl;

    return 0;
}
