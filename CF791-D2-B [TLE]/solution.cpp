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

template <class T>
T modpow(T x, T n, T m) {
    if(n == 0) return 1 % m;
    ll u = modpow(x, n/2, m);
    u = (u*u)%m;
    if(n%2 == 1) u = (u*x)%m;
    return u;
}

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if(a.first == b.first) return a.second < b.second; 
    return a.first < b.first;
}

int main () {
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    
    unordered_set<int> seen;
    vector<unordered_set<int>> vertices;
    vector<int> edges;
    
    vector<pair<int, int>> edgelist;
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        a < b ? edgelist.push_back({a, b}) : edgelist.push_back({b, a});
    }

    sort(edgelist.begin(), edgelist.end(), cmp);

    for(int i = 0; i < m; i++) {
        a = edgelist[i].first;
        b = edgelist[i].second;

        if(!seen.count(a) && !seen.count(b)) {
            unordered_set <int> t;
            vertices.push_back(t);
            vertices[vertices.size()-1].insert(a);
            vertices[vertices.size()-1].insert(b);

            edges.push_back(1);
        } else {
            for(int j = 0; j < vertices.size(); j++) {
                if(vertices[j].count(a) || vertices[j].count(b)) {
                    edges[j]++;
                    vertices[j].insert(a);
                    vertices[j].insert(b);
                    break;
                }
            }
        }

        seen.insert(a);
        seen.insert(b);
    }

    bool done = true;
    for(int i = 0; i < vertices.size(); i++) {
        if(vertices[i].size()*(vertices[i].size()-1)/2 != edges[i]) {
            done = false;
            break;
        }
    }

    done ? printf("YES\n") : printf("NO\n");

    return 0;
}
