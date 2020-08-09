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
T modpow(T x, T n, T m) {
    if (n == 0) return 1 % m;
    ll u = modpow(x, n / 2, m);
    u = (u * u) % m;
    if (n % 2 == 1) u = (u * x) % m;
    return u;
}

int main() {
    int n;
    scanf("%d", &n);

    ll total = 0;
    map<pair<int, int>, int> seen;
    unordered_map<int, int> xCoords, yCoords;

    int a, b;
    while (n--) {
        scanf("%d %d", &a, &b);
        if (seen.count({a, b}))
            seen[{a, b}]++;
        else {
            seen.insert({{a, b}, 1});
        }

        if (!xCoords.count(a)) {
            xCoords.insert({a, 0});
        }
        if (!yCoords.count(b)) {
            yCoords.insert({b, 0});
        }

        xCoords[a]++;
        yCoords[b]++;
    }

    for (const auto& p : xCoords) {
        if (p.second > 1) total += (ll)p.second * (ll)(p.second - 1) / (ll)2;
    }
    for (const auto& p : yCoords) {
        if (p.second > 1) total += (ll)p.second * (ll)(p.second - 1) / (ll)2;
    }
    for (const auto& p : seen) {
        if (p.second > 1) total -= (ll)p.second * (ll)(p.second - 1) / (ll)2;
    }
    printf("%lld\n", total);

    return 0;
}
