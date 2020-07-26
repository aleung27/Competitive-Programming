#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define X real()
#define Y imag()
#define EPS 0.000000001
#define M_PI 3.14159265358979323846
#define CROSSPROD(a, b) (conj(a)*(b)).Y
#define DOTPROD(a, b) ((a).X*(b).X + (a).Y+(b).Y)
#define FASTIO ios::sync_with_stdio(false);

int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};

template <class T>
T gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

bool seen[105] = {false};

void dfs(int at, int to, int weight, vector<pair<int, int>> adjlist[]) {
    seen[at] = true;
    if(at == to) return;

    for(int i = 0; i < adjlist[at].size(); i++) {
        if(adjlist[at][i].second == weight && !seen[adjlist[at][i].first]) {
            dfs(adjlist[at][i].first, to, weight, adjlist);
        }
    }
}

int main () {
    int n, m;
    scanf("%d %d", &n, &m);

    vector<pair<int, int>> adjlist[n+1];
    int from, to, weight;
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &from, &to, &weight);
        adjlist[from].push_back({to, weight});
        adjlist[to].push_back({from, weight});
    }

    int q;
    scanf("%d", &q);

    for(; q > 0; q--) {
        int count = 0;
        bool colours[105] = {false};
        scanf("%d %d", &to, &from);

        for(int i = 0; i < adjlist[from].size(); i++) {
            memset(seen, false, 105);
            if(!colours[adjlist[from][i].second]) dfs(from, to, adjlist[from][i].second, adjlist);
            if(seen[to]) count++;
            colours[adjlist[from][i].second] = true;
        }

        printf("%d\n", count);
    }

    return 0;
}
