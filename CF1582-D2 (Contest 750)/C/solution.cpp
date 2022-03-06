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
        int n;
        string s;
        cin >> n >> s;

        int best = INT_MAX;
        for (int i = 97; i <= 122; i++) {
            int left = 0;
            int right = n - 1;

            int changes = 0;
            bool ok = true;

            while (left < right) {
                if (s[left] == s[right]) {
                    left++;
                    right--;
                } else if (s[left] == (char)i) {
                    left++;
                    changes++;
                } else if (s[right] == (char)i) {
                    right--;
                    changes++;
                } else {
                    ok = false;
                    break;
                }
            }

            if (ok && changes < best) best = changes;
        }

        if (best == INT_MAX) {
            cout << "-1" << endl;
        } else {
            cout << best << endl;
        }
    }

    return 0;
}