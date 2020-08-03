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

bool comp(const pair<int, int>&a, const pair<int, int>&b) {
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int main () {
    int n, diff, a, b;
    scanf("%d %d", &n, &diff);

    vector<pair<int, int>> vals;
    while(n--) {
        scanf("%d %d", &a, &b);
        vals.push_back({a, b});
    }

    sort(vals.begin(), vals.end(), comp);

    int start = 0, end = 0;
    ll ans = 0, sum = 0;

    while(end < vals.size()) {
        if(end == 0) {
            while(vals[end].first-vals[start].first < diff) {
                sum += vals[end].second;
                end++;
                if(end == vals.size()) break;
            }
            ans = max(ans, sum);
            continue;
        }

        sum += vals[end].second;
        while(vals[end].first-vals[start].first >= diff) {
            sum -= vals[start].second;
            start++;
        }

        ans = max(ans, sum);
        end++;
    }

    printf("%lld\n", ans);

    return 0;
}
