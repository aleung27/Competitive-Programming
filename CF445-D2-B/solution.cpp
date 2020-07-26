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

bool seen[55] = {false};

void dfs(int at, vector<int> adjlist[]) {
    seen[at] = true;

    for(int i = 0; i < adjlist[at].size(); i++) {
        if(!seen[adjlist[at][i]]) dfs(adjlist[at][i], adjlist);
    }
}

int main () {
    int n, m;
    scanf("%d %d", &n, &m);

    vector<int> adjlist[n+1];
    int v1, v2;

    for(int i = 0; i < m; i++) {
        scanf("%d %d", &v1, &v2);
        adjlist[v1].push_back(v2);
        adjlist[v2].push_back(v1);
    }

    int useless = 0;
    int components = 0;
    for(int i = 1; i <= n; i++) {
        if(!adjlist[i].size()) useless++;
        else if(!seen[i]) {
            dfs(i, adjlist);
            components++;
        }
    }

    ll total = 1;
    total = total << max(0, (n-useless-components));

    printf("%lld\n", total);


    return 0;
}
