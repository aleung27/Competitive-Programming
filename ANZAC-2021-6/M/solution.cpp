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

int oneBits(int x) {
    int cnt = 0;
    for (int i = 0; 1 << i <= x; i++) {
        if (x & (1 << i)) cnt++;
    }
    return cnt;
}
// TODO: Incomplete
int main() {
    FASTIO
    string s;

    while (1) {
        cin >> s;
        map<char, int> chars;
        bool invalid = false;

        if (s == "#") continue;

        for (const auto& e : s) {
            if (chars.count(e))
                chars[e]++;
            else
                chars.insert({e, 1});
        }

        for (const auto& e : chars) {
            if (e.second != 2) {
                cout << "0" << endl;
                invalid = true;
            }
        }

        if (invalid) continue;

        ll DP[1 << s.length()];
        DP[0] = 1;

        for (int i = 1; i < (1 << s.length()); i++) {
            DP[i] = 0;
            int ones = oneBits(i);
            if (ones % 2) {
                continue;
            }

            for (int j = s.length() - 1; j > 0; j--) {
                for (int k = j - 1; k >= 0; k--) {
                    if (i & (i << j) && i & (i << k) && (j - k) % 2) {
                        // both bits are already on
                        // Toggle them off and see
                        DP[i] += DP[i ^ ((1 << j) | (1 << k))];
                    }
                }
            }
            cout << bitset<4>(i) << "  " << DP[i] << endl;
        }

        cout << DP[1 << s.length() - 1] << endl;
    }
    return 0;
}
