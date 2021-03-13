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
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;

        pair<ll, ll> schedule[n];
        ll extraTime[n];

        for (int i = 0; i < n; i++) {
            cin >> schedule[i].first >> schedule[i].second;
        }

        for (int i = 0; i < n; i++) {
            cin >> extraTime[i];
        }

        ll time = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0)
                time = extraTime[i] + schedule[0].first;
            else {
                ll diff =
                    (schedule[i - 1].second - schedule[i - 1].first) / 2 +
                    ((schedule[i - 1].second - schedule[i - 1].first) % 2 != 0);

                time = max(schedule[i - 1].second, time + diff);
                time +=
                    schedule[i].first - schedule[i - 1].second + extraTime[i];
            }
        }

        // time = max(
        //     schedule[n - 1].second,
        //     time + (schedule[n - 1].second - schedule[n - 1].first) / 2 +
        //         ((schedule[n - 1].second - schedule[n - 1].first) % 2 != 0));

        cout << time << endl;
    }

    return 0;
}