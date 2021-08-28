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

bool sortx(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

bool sorty(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    FASTIO
    int n;
    cin >> n;

    vector<pair<ll, ll>> pts;
    for (int i = 0; i < n; i++) {
        pair<ll, ll> a;
        cin >> a.first >> a.second;
        pts.push_back(a);
    }

    ll totalx = 0, totaly = 0;
    ll sumx = 0, sumy = 0;
    sort(pts.begin(), pts.end(), sortx);

    for (ll i = 0; i < n; i++) {
        totalx += pts[i].first * i - sumx;
        sumx += pts[i].first;
    }

    sort(pts.begin(), pts.end(), sorty);

    for (ll i = 0; i < n; i++) {
        totaly += pts[i].second * i - sumy;
        sumy += pts[i].second;
    }

    cout << totalx + totaly << endl;

    return 0;
}
