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
T lcm(T a, T b) {
    return a * b / gcd<T>(a, b);
}

template <class T>
T modpow(T x, T n, T m) {
    if (n == 0) return 1 % m;
    ll u = modpow(x, n / 2, m);
    u = (u * u) % m;
    if (n % 2 == 1) u = (u * x) % m;
    return u;
}

bool comp(const pair<int, int> &a, const pair<int, int> &b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    int t;
    scanf("%d", &t);

    for(int i = 1; i <= t; i++) {
        int n, max;
        scanf("%d %d", &n, &max);

        vector<pair<int, int>> ppl;
        for(int j = 0; j < n; j++) {
            int a;
            scanf("%d", &a);
            ppl.push_back({j+1, a % max == 0 ? a/max : a/max + 1 });
        }

        sort(ppl.begin(), ppl.end(), comp);

        printf("Case #%d: ", i);
        for(auto iter = ppl.begin(); iter != ppl.end(); iter++) {
            iter != ppl.end()-1 ? printf("%d ", iter->first) : printf("%d\n", iter->first);
        }
    }

    return 0;
}
