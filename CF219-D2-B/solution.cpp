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
    ll n, d;
    cin >> n >> d;

    ll ans = n;

    string best = to_string(ans);

    for (int i = best.length() - 1; i >= 1; i--) {
        if (best[i] == '9') continue;

        best[i] = '9';
        for (int j = i - 1; j >= 0; j--) {
            if (best[j] != '0') {
                best[j]--;
                break;
            } else {
                best[j] = '9';
            }
        }

        ll newAns = stoll(best);
        if (n - newAns <= d) ans = newAns;
    }

    cout << ans << endl;

    return 0;
}
