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
T modpow(T x, T n, T m) {
    if (n == 0) return 1 % m;
    ll u = modpow(x, n / 2, m);
    u = (u * u) % m;
    if (n % 2 == 1) u = (u * x) % m;
    return u;
}

unordered_map<string, string> parent;
unordered_map<string, int> size;

struct edge {
    string to, from;
    int cost;
};

bool comp(const edge& a, const edge& b) { return a.cost < b.cost; }

string find(string x) {
    while (x != parent[x]) x = parent[x];
    return x;
}

void join(string a, string b) {
    a = find(a);
    b = find(b);
    if (size[a] < size[b]) swap(a, b);
    size[a] += size[b];
    parent[b] = a;
}

int main() {
    FASTIO
    int t;
    cin >> t;

    while (t--) {
        int n, m, weight;
        string a, b;
        size.clear();
        parent.clear();
        cin >> n >> m;

        vector<edge> edgelist;
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> weight;
            edgelist.push_back({a, b, weight});

            if (!size.count(a)) {
                size.insert({a, 1});
                parent.insert({a, a});
            }

            if (!size.count(b)) {
                size.insert({b, 1});
                parent.insert({b, b});
            }
        }

        sort(edgelist.begin(), edgelist.end(), comp);

        ll ans = 0;
        int counter = 0;
        for (int i = 0; i < edgelist.size() && counter != n - 1; i++) {
            if (find(edgelist[i].to) != find(edgelist[i].from)) {
                join(edgelist[i].to, edgelist[i].from);
                ans += edgelist[i].cost;
            }
        }

        cout << ans << endl;
        if (t) cout << endl;
    }

    return 0;
}
