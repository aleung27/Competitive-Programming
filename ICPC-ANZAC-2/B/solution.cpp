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
    ll n, s;
    cin >> n >> s;

    vector<ll> nums;
    ll ans = LONG_LONG_MAX;
    int pos = 0;

    for (int i = 0; i < n; i++) {
        ll next;
        cin >> next;
        nums.push_back(next);

        if (next < ans) {
            ans = next;
            pos = i;
        }
    }

    while (1) {
        int pos2 = 0;
        ll ans2 = LONG_LONG_MAX;
        bool done = false;
        for (int i = pos + 1; i < n; i++) {
            nums[i] -= s * (pos + 1);

            if (nums[i] < ans) {
                done = true;
                break;
            }

            else if (ans2 > nums[i]) {
                pos2 = i;
                ans2 = nums[i];
            }
        }
        if (done) break;
        ans = max(ans, ans2);
        pos = pos2;
    }

    cout << ans << endl;

    return 0;
}
