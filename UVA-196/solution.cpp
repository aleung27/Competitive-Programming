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

int r, c;

ll compute(int atI, int atJ, vector<vector<string>>& grid,
           vector<vector<bool>>& seen, vector<vector<ll>>& ans) {
    if (seen[atI][atJ]) return ans[atI][atJ];
    seen[atI][atJ] = true;

    try {
        ll cell = stoi(grid[atI][atJ], NULL, 10);
        ans[atI][atJ] = cell;
        return cell;
    } catch (invalid_argument& err) {
        string s = grid[atI][atJ].replace(0, 1, "");
        ll total = 0;
        int pos = 0;

        while ((pos = s.find("+")) != string::npos) {
            string cell = s.substr(0, pos);

            int nextJ = 0, nextI = 0;
            int i = 0;
            for (; i < cell.length(); i++) {
                if (isdigit(cell[i])) break;
                nextJ *= 26;
                nextJ += (cell[i] - '@');
            }

            total += compute(stoi(cell.substr(i, cell.length() - 1)) - 1,
                             nextJ - 1, grid, seen, ans);

            s.erase(0, pos + 1);
        }

        int nextJ = 0, nextI = 0;
        int i = 0;
        for (; i < s.length(); i++) {
            if (isdigit(s[i])) break;
            nextJ *= 26;
            nextJ += (s[i] - '@');
        }

        total += compute(stoi(s.substr(i, s.length() - 1)) - 1, nextJ - 1, grid,
                         seen, ans);

        ans[atI][atJ] = total;
        return total;
    }
}

int main() {
    FASTIO
    int t;
    cin >> t;

    while (t--) {
        cin >> c >> r;

        vector<vector<string>> grid;
        vector<vector<ll>> ans;
        vector<vector<bool>> seen;

        for (int i = 0; i < r; i++) {
            vector<string> row;
            vector<ll> aRow;
            vector<bool> sRow;
            for (int j = 0; j < c; j++) {
                string s;
                cin >> s;

                row.push_back(s);
                sRow.push_back(false);
                aRow.push_back(LONG_LONG_MIN);
            }
            ans.push_back(aRow);
            grid.push_back(row);
            seen.push_back(sRow);
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (!seen[i][j]) compute(i, j, grid, seen, ans);
                j == c - 1 ? cout << ans[i][j] << endl
                           : cout << ans[i][j] << " ";
            }
        }
    }

    return 0;
}
