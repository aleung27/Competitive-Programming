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

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first > b.first;
}

int main() {
    int n, k, a;
    vector<pair<int, int>> towers;

    vector<pair<int, int>> moves;

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        towers.push_back({a, i + 1});
    }

    sort(towers.begin(), towers.end(), cmp);

    int cnt = 0;
    int dist = towers[0].first - towers[n - 1].first;

    while (dist != 0 && cnt < k) {
        towers[0].first--;
        towers[n - 1].first++;
        moves.push_back({towers[0].second, towers[n - 1].second});
        cnt++;
        sort(towers.begin(), towers.end(), cmp);
        dist = towers[0].first - towers[n - 1].first;
    }

    printf("%d %d\n", dist, cnt);
    for (const auto& p : moves) {
        printf("%d %d\n", p.first, p.second);
    }

    return 0;
}
