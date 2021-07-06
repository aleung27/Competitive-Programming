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

int n;

vector<int> solve(vector<vector<int>> &adj, vector<bool> colour, int at,
                  vector<int> blacks) {
    bool canBlack = true;
    for (const auto &e : adj[at]) {
        if (colour[e]) {
            canBlack = false;
            break;
        }
    }

    if (at == n - 1) {
        if (canBlack) {
            blacks.push_back(at);
        }
        return blacks;
    }

    vector<int> ans1, ans2;
    ans1 = solve(adj, colour, at + 1, blacks);

    if (canBlack) {
        blacks.push_back(at);
        colour[at] = true;
        ans2 = solve(adj, colour, at + 1, blacks);
        colour[at] = false;
        blacks.pop_back();
    } else {
        return ans1;
    }

    return ans2.size() > ans1.size() ? ans2 : ans1;
}

int main() {
    FASTIO
    int t;
    cin >> t;

    while (t--) {
        int m;
        cin >> n >> m;

        vector<vector<int>> adj;
        vector<bool> colour;  // 0->W, 1->B
        for (int i = 0; i < n; i++) {
            adj.push_back(vector<int>());
            colour.push_back(false);
        }

        for (int i = 0; i < m; i++) {
            int to, from;
            cin >> to >> from;
            to--;
            from--;

            adj[to].push_back(from);
            adj[from].push_back(to);
        }

        vector<int> ans = solve(adj, colour, 0, vector<int>());
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] + 1;
            i == ans.size() - 1 ? cout << endl : cout << " ";
        }
    }

    return 0;
}
