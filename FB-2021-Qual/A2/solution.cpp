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

pair<int, int> bfs(int at, vector<vector<int>>& adjlist, int target) {
    queue<pair<int, int>> q;
    auto seen = vector<int>(26, false);
    q.push({at, 0});
    seen[at] = true;

    while (!q.empty()) {
        auto current = q.front();
        q.pop();

        if (current.first == target) return current;

        for (const auto& e : adjlist[current.first]) {
            if (!seen[e]) {
                seen[e] = true;
                q.push({e, current.second + 1});
            }
        }
    }

    return {-1, -1};
}

int main() {
    FASTIO
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int t = 1; t <= n; t++) {
        string s, transformation;
        int e;
        int ans = INT_MAX;
        vector<vector<int>> adjlist(26, vector<int>());

        cin >> s >> e;

        for (int i = 0; i < e; i++) {
            cin >> transformation;
            adjlist[transformation[0] - 'A'].push_back(transformation[1] - 'A');
        }

        for (int i = 0; i < 26; i++) {
            int currentVal = 0;
            bool ok = true;

            for (int j = 0; j < s.length(); j++) {
                auto res = bfs(s[j] - 'A', adjlist, i);

                if (res.first != -1)
                    currentVal += res.second;
                else {
                    ok = false;
                    break;
                }
            }

            if (ok) ans = min(ans, currentVal);
        }

        if (ans == INT_MAX) ans = -1;
        cout << "Case #" << t << ": " << ans << endl;
    }

    return 0;
}
