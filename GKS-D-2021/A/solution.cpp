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

int main() {
    FASTIO
    int t;
    cin >> t;

    for (int a = 1; a <= t; a++) {
        int grid[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == 1 && j == 1) continue;
                cin >> grid[i][j];
            }
        }

        int count = 0;

        for (int i = 0; i < 3; i++) {
            if (i == 1) continue;
            if (grid[i][0] - grid[i][1] == grid[i][1] - grid[i][2]) count++;
            if (grid[0][i] - grid[1][i] == grid[1][i] - grid[2][i]) count++;
        }

        map<int, int> map;
        if ((grid[1][2] - grid[1][0]) % 2 == 0) {
            if (map.count(grid[1][0] + (grid[1][2] - grid[1][0]) / 2))
                map[grid[1][0] + (grid[1][2] - grid[1][0]) / 2]++;
            else
                map.insert({grid[1][0] + (grid[1][2] - grid[1][0]) / 2, 1});
        }

        if ((grid[2][1] - grid[0][1]) % 2 == 0) {
            if (map.count(grid[0][1] + (grid[2][1] - grid[0][1]) / 2))
                map[grid[0][1] + (grid[2][1] - grid[0][1]) / 2]++;
            else
                map.insert({grid[0][1] + (grid[2][1] - grid[0][1]) / 2, 1});
        }

        if ((grid[2][2] - grid[0][0]) % 2 == 0) {
            if (map.count(grid[0][0] + (grid[2][2] - grid[0][0]) / 2))
                map[grid[0][0] + (grid[2][2] - grid[0][0]) / 2]++;
            else
                map.insert({grid[0][0] + (grid[2][2] - grid[0][0]) / 2, 1});
        }

        if ((grid[2][0] - grid[0][2]) % 2 == 0) {
            if (map.count(grid[0][2] + (grid[2][0] - grid[0][2]) / 2))
                map[grid[0][2] + (grid[2][0] - grid[0][2]) / 2]++;
            else
                map.insert({grid[0][2] + (grid[2][0] - grid[0][2]) / 2, 1});
        }

        bool done = false;
        for (const auto& e : map) {
            if (e.second >= 2) {
                count += e.second;
                done = true;
                break;
            }
        }
        if (!done && map.size()) count++;

        cout << "Case #" << a << ": " << count << endl;
    }

    return 0;
}
