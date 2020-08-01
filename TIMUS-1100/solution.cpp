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

struct entry {
    int id, problems, init;
};

bool comp(const entry& a, const entry& b) {
    if(a.problems == b.problems) {
        return a.init < b.init;
    }
    return a.problems > b.problems;
}

int main () {
    int n;
    scanf("%d", &n);

    vector<entry> entries;
    for(int i = 0; i < n; i++) {
        entry e;
        scanf("%d %d", &e.id, &e.problems);
        e.init = i;
        entries.push_back(e);    
    }

    sort(entries.begin(), entries.end(), comp);

    for(const entry& e: entries) {
        printf("%d %d\n", e.id, e.problems);
    }

    return 0;
}
