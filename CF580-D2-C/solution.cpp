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

int counter = 0;
int m;
bool hasCat[100005] = {false};

void dfs(int at, int from, int cats, vector<int> (&adj)[100005]) {
    if (adj[at].size() == 1 && adj[at][0] == from) counter++;

    for (const auto& e : adj[at]) {
        if (e != from && hasCat[e] + cats <= m) {
            if (hasCat[e] && hasCat[e] + cats <= m)
                dfs(e, at, cats + hasCat[e], adj);
            else
                dfs(e, at, 0, adj);
        }
    }
}

int main() {
    FASTIO
    int n;
    cin >> n >> m;

    vector<int> adj[100005];

    for (int i = 0; i < n; i++) cin >> hasCat[i];
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }

    dfs(0, -1, hasCat[0] ? 1 : 0, adj);

    cout << counter << endl;

    return 0;
}
