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

struct group {
    int ppl, price, index;
};

bool comp(const group& a, const group& b) {
    if(a.price == b.price) return a.ppl > b.ppl;
    return a.price > b.price;
}

bool secondComp(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first < b.first;
}

int main () {
    int n, ppl, price;
    scanf("%d", &n);

    vector<group> groups;
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &ppl, &price);
        groups.push_back({ppl, price, i+1});
    }

    sort(groups.begin(), groups.end(), comp);

    int t;
    vector<pair<int, int>> tables;

    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        scanf("%d", &ppl);
        tables.push_back({ppl, i+1});
    }

    sort(tables.begin(), tables.end(), secondComp);

    int total = 0, orders = 0;
    vector<pair<int, int>> ans;

    for(int i = 0; i < groups.size(); i++) {
        for(int j = 0; j < tables.size(); j++) {
            if(groups[i].ppl <= tables[j].first) {
                total += groups[i].price;
                orders++;
                ans.push_back({groups[i].index, tables[j].second});
                tables[j].first = -1;
                break;
            }
        }
    }

    printf("%d %d\n", orders, total);
    for(const auto& a: ans) {
        printf("%d %d\n", a.first, a.second);
    }

    return 0;
}
