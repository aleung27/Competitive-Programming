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

struct edge {
    int to, from;
    double dist;
};

vector<edge> edgelist;
vector<int> sizes;
vector<int> links;

bool comp(const edge& a, const edge& b) {
    return a.dist < b.dist;
}

int find(int a) {
    while(links[a] != a) a = links[a];
    return a;
}

void join(int a, int b) {
    a = find(a);
    b = find(b);

    if(sizes[a] < sizes[b]) swap(a,b);
    sizes[a] += sizes[b];
    links[b] = a;
}

int main () {
    int t;
    scanf("%d", &t);

    while(t--) {
        int s, n, a, b;
        edgelist.clear();
        sizes.clear();
        links.clear();
        scanf("%d %d", &s, &n);

        vector<complex<double>> nodes;
        for(int i = 0; i < n; i++) {
            scanf("%d %d", &a, &b);
            nodes.push_back(complex<double>(a, b));
            sizes.push_back(1);
            links.push_back(i);
        }

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                edge e = {
                    i,
                    j,
                    abs(nodes[i]-nodes[j])
                };

                edgelist.push_back(e);
            }
        }

        sort(edgelist.begin(), edgelist.end(), comp);

        int counter = 0;
        vector<double> dists;

        for(int i = 0; i < edgelist.size(); i++) {
            if(counter == n-1) break;
            if(find(edgelist[i].to) != find(edgelist[i].from)) {
                join(edgelist[i].to, edgelist[i].from);
                dists.push_back(edgelist[i].dist);
                counter++;
            }
        }

        sort(dists.begin(), dists.end());
        if(s >= n) {
            printf("0.00\n");
        } else {
            printf("%.2lf\n", dists[min(n-2, n-1-s)]);
        }
    }



    return 0;
}
