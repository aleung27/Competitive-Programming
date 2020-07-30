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

int links[105];
int size[105] = {1};

struct edge {
    int to, from, weight;
};

bool comp(const edge& a, const edge& b) {
    return a.weight < b.weight;
}

int find(int a) {
    while(links[a] != a) a = links[a];
    return a;
}

void join(int a, int b) {
    a = find(a);
    b = find(b);

    if(size[a] < size[b]) swap(a,b);
    size[a] += size[b];
    links[b] = a;
}

int main () {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n, m, a, b, w;
        scanf("%d %d", &n, &m);

        vector<edge> edgelist;

        for(int i = 0; i < m; i++) {
            scanf("%d %d %d", &a, &b, &w);
            edge e = {a, b, w};
            edgelist.push_back(e);
            if(i < n) {
                links[i+1] = i+1;
                size[i+1] = 1;
            }
        }

        sort(edgelist.begin(), edgelist.end(), comp);

        int lowest = 0;
        int secondLowest = INT_MAX;
        vector<int> skips;
        // Do one mst and then add the index of edges and iterate through them excluding 1 by 1
        
        for(int i = 0; i < (int)edgelist.size(); i++) {
            if(find(edgelist[i].to) != find(edgelist[i].from)) {
                join(edgelist[i].to, edgelist[i].from);
                lowest += edgelist[i].weight;
                skips.push_back(i);
            }
        }

        for(int i = 0; i < (int)skips.size(); i++) {
            memset(size, 1, 105*sizeof(int));
            for(int j = 1; j < 105; j++) links[j] = j;
            int counter = 0;
            int sum = 0;

            for(int j = 0; j < (int)edgelist.size(); j++) {
                if(j == skips[i]) continue;
                if(counter == n-1) break;
                if(find(edgelist[j].to) != find(edgelist[j].from)) {
                    join(edgelist[j].to, edgelist[j].from);
                    sum += edgelist[j].weight;
                    counter++;
                }
            }

            if(sum < secondLowest && sum >= lowest) secondLowest = sum;
        }

        printf("%d %d\n", lowest, secondLowest);
    }

    return 0;
}
