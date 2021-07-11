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

bool compare(const pair<ll, ll>& a, const pair<ll, ll>& b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }

    return a.first > b.first;
}

int main() {
    FASTIO
    int t;
    cin >> t;

    for (int a = 1; a <= t; a++) {
        ll n, c;
        cin >> n >> c;

        ll total = 0;
        map<ll, ll> segments;
        vector<pair<ll, ll>> values;

        for (ll i = 0; i < n; i++) {
            ll l, r;
            cin >> l >> r;

            if (l == r)
                continue;
            else if (l == r - 1)
                total++;
            else {
                if (segments.count(l + 1))
                    segments[l + 1]++;
                else
                    segments.insert({l + 1, 1});

                if (segments.count(r))
                    segments[r]--;
                else
                    segments.insert({r, -1});

                total++;
            }
        }

        ll extras = LLONG_MIN;
        for (auto e = segments.begin(); e != segments.end(); e++) {
            auto nextEl = next(e, 1);

            if (extras == LLONG_MIN) {
                extras = e->second;
            } else {
                extras += e->second;
            }

            if (nextEl == segments.end())
                values.push_back({extras, 1});
            else
                values.push_back({extras, nextEl->first - e->first});
        }

        sort(values.begin(), values.end(), compare);

        for (ll i = 0; i < values.size(); i++) {
            if (c == 0) break;
            total += values[i].first * min(values[i].second, c);
            c -= min(values[i].second, c);
        }

        cout << "Case #" << a << ": " << total << endl;
    }

    return 0;
}
