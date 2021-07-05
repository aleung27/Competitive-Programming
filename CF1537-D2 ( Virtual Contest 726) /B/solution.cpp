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

int main() {
    FASTIO
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        pair<int, int> start;

        cin >> r >> c >> start.first >> start.second;

        vector<pair<int, int>> pts;
        if (start.first != 1 && start.second != 1) pts.push_back({1, 1});
        if (start.first != r && start.second != 1) pts.push_back({r, 1});
        if (start.first != r && start.second != c) pts.push_back({r, c});
        if (start.first != 1 && start.second != c) pts.push_back({1, c});

        if (pts.size() == 0) {
            if (r == 1) {
                cout << "1 1 1 " << c << endl;
            } else if (c == 1) {
                cout << "1 1 " << r << " 1" << endl;
            }
        } else if (pts.size() == 1)
            cout << pts[0].first << " " << pts[0].second << " " << pts[0].first
                 << " " << pts[0].second << endl;
        else if (pts.size() == 2)
            cout << pts[0].first << " " << pts[0].second << " " << pts[1].first
                 << " " << pts[1].second << endl;
        else if (pts.size() == 4)
            cout << pts[0].first << " " << pts[0].second << " " << pts[2].first
                 << " " << pts[2].second << endl;
    }

    return 0;
}
