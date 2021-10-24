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
        ll n, next;
        ll sum = 0;

        cin >> n;

        vector<ll> vals;
        for (int i = 0; i < n; i++) {
            cin >> next;
            vals.push_back(next);
            sum += next;
        }

        for (int i = 0; i < n; i++) {
            if (sum - vals[i] == 0) continue;
            ll LCM = lcm<ll>(abs(vals[i]), abs(sum - vals[i]));
            ll factor1 = LCM / abs(vals[i]);
            ll factor2 = LCM / abs(sum - vals[i]);
            if (abs(factor1 + (n - 1) * (-factor2)) <= 1e9) {
                int multFactor = 1;
                if (sum - vals[i] < 0 && vals[i] > 0 ||
                    vals[i] < 0 && sum - vals[i] > 0) {
                    multFactor = -1;
                }

                for (int j = 0; j < n; j++) {
                    if (j == i)
                        cout << factor1;
                    else
                        cout << -1 * factor2 * multFactor;

                    j == n - 1 ? cout << endl : cout << " ";
                }
                break;
            }
        }
    }

    return 0;
}
