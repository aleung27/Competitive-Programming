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

struct path {
    int to, l, c;
};

vector<path> adj[50005];
int seen[50005];
path parent[50005];

void dfs(int at, int l, int c, int from) {
    parent[at] = {from, l, c};
    seen[at] = true;
    // cout << at << endl;
    if (at == 1) return;

    for (const auto& p : adj[at]) {
        if (!seen[p.to]) dfs(p.to, p.l, p.c, at);
    }
}

int main() {
    FASTIO
    int t;
    cin >> t;

    for (int a = 1; a <= t; a++) {
        int n, q;
        cin >> n >> q;

        for (int i = 0; i < 50005; i++) {
            adj[i].clear();
            seen[i] = false;
        }

        for (int i = 0; i < n - 1; i++) {
            int n1, n2, l, c;
            cin >> n1 >> n2 >> l >> c;

            adj[n1].push_back({n2, l, c});
            adj[n2].push_back({n1, l, c});
        }

        cout << "Case #" << a << ": ";
        for (int i = 0; i < q; i++) {
            int start, w;
            cin >> start >> w;

            for (int j = 0; j < 50005; j++) {
                seen[j] = false;
            }

            dfs(start, -1, -1, -1);

            int ans = -1;
            path at = {1, 0, 0};
            while (at.to != start) {
                at = parent[at.to];
                // cout << at.l << "/" << at.c << "/";

                if (w >= at.l) {
                    if (ans == -1)
                        ans = at.c;
                    else {
                        // cout << ans << "///" << next.second;
                        ans = gcd<int>(ans, at.c);
                    }
                }
            }

            if (ans == -1) ans = 0;

            i == q - 1 ? cout << ans << endl : cout << ans << " ";
        }
    }

    return 0;
}
