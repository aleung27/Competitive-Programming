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

int counter = 0;
int link[755];
int size[755] = {1};

struct edge {
    int from, to;
    double dist;
};

bool comp (const edge& a, const edge& b) {
    return a.dist < b.dist;
}

int find(int x) {
    while(x != link[x]) x = link[x];
    return x;
}

void join(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return;

    if(size[a] < size[b]) swap(a, b);
    size[a] += size[b];
    link[b] = a;
    counter++;
}

int main () {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        counter = 0;
        scanf("%d", &n);

        vector<complex<double>> coords;
        vector<edge> edgelist; 
        int a, b;

        for(int i = 0; i < n; i++) {
            scanf("%d %d", &a, &b);
            complex<double> temp(a, b);
            coords.push_back(temp);
            link[i+1] = i+1;
            size[i+1] = 1;
        }

        for(int i = 0; i < coords.size(); i++) {
            for(int j = i + 1; j < coords.size(); j++) {
                edge e = {
                    i+1,
                    j+1,
                    abs(coords[i]-coords[j])
                };

                edgelist.push_back(e);
            }
        }

        sort(edgelist.begin(), edgelist.end(), comp);

        int m;
        scanf("%d", &m);
        for(int i = 0; i < m; i++) {
            scanf("%d %d", &a, &b);
            join(a, b);
        }

        bool done = false;
        for(int i = 0; i < edgelist.size(); i++) {
            if(counter == n-1) break;

            if(find(edgelist[i].from) != find(edgelist[i].to)) {
                join(edgelist[i].from, edgelist[i].to);
                printf("%d %d\n", edgelist[i].from, edgelist[i].to);
                done = true;
            }
        }

        if(!done) {
            printf("No new highways need\n");
        }

        if(t) printf("\n");
    }


    return 0;
}
