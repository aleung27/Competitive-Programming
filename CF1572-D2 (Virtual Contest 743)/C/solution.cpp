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

void kahn(set<int>& starts, vector<vector<int>>& graph, vector<int>& indegree,
          int n) {
    int last = 0, visited = 0;
    vector<int> path;

    while (!starts.empty()) {
        auto at = starts.upper_bound(last);
        if (at == starts.end()) at = starts.begin();

        int current = *at;
        last = current;

        starts.erase(at);
        path.push_back(current);
        visited++;

        // cout << "vaL " << current << endl;

        for (int i = 0; i < graph[current].size(); i++) {
            indegree[graph[current][i]]--;
            if (indegree[graph[current][i]] == 0)
                starts.insert(graph[current][i]);
        }
    }

    if (visited != n)
        cout << "-1" << endl;
    else {
        int total = 1;
        for (int i = 1; i < path.size(); i++) {
            if (path[i] < path[i - 1]) total++;
        }

        cout << total << endl;
    }
}

int main() {
    FASTIO
    int t;
    cin >> t;

    while (t--) {
        int n, deps, dummy;
        bool cycle = false;
        cin >> n;

        vector<vector<int>> graph(n + 1, vector<int>());
        vector<int> indegree(n + 1, 0);
        set<int> starts;

        for (int i = 1; i <= n; i++) {
            cin >> deps;
            if (deps == 0) starts.insert(i);
            for (int j = 0; j < deps; j++) {
                cin >> dummy;
                graph[dummy].push_back(i);
                indegree[i]++;
            }
        }

        kahn(starts, graph, indegree, n);
    }

    return 0;
}