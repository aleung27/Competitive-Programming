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
    int r, c, next;
    cin >> r >> c;

    map<ll, pair<vector<ll>, vector<ll>>> colours;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> next;
            if (!colours.count(next))
                colours.insert({next, {vector<ll>(), vector<ll>()}});

            colours[next].first.push_back(j);
            colours[next].second.push_back(i);
        }
    }

    ll total = 0;

    for (const auto& entry : colours) {
        int colour = entry.first;
        vector<ll> xCoord = entry.second.first;
        vector<ll> yCoord = entry.second.second;

        sort(xCoord.begin(), xCoord.end());
        sort(yCoord.begin(), yCoord.end());

        ll resX = 0, resY = 0;
        ll sumX = 0, sumY = 0;
        for (ll i = 0; i < xCoord.size(); i++) {
            resX += xCoord[i] * i - sumX;
            resY += yCoord[i] * i - sumY;
            sumX += xCoord[i];
            sumY += yCoord[i];
        }

        total += resX + resY;
    }

    cout << total << endl;

    return 0;
}
