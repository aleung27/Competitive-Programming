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

bool seen[200050] = {false};
vector<int> adj[200050];

void dfs(int at) {
    if (seen[at]) return;
    seen[at] = true;

    for (const auto& node : adj[at]) {
        dfs(node);
    }
}

int main() {
    FASTIO
    int n;
    string s;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s;

        for (const auto& c : s) {
            adj[i].push_back(n + c - 'a');
            adj[n + c - 'a'].push_back(i);
        }
    }

    int count = 0;

    for (int i = n; i < n + 26; i++) {
        if (!seen[i] && adj[i].size()) {
            dfs(i);
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
