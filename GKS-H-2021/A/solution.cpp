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

    for (int a = 1; a <= t; a++) {
        string s;
        string f;
        cin >> s >> f;

        bool isPresent[26];
        memset(isPresent, 0, sizeof(bool) * 26);
        for (const auto &c : f) isPresent[c - 'a'] = true;

        ll count = 0;
        for (int i = 0; i < s.length(); i++) {
            int left = s[i] - 'a';
            int right = s[i] - 'a';

            for (int j = 0; j <= 13; j++) {
                if (isPresent[(left - j + 26) % 26]) {
                    count += j;
                    break;
                } else if (isPresent[(right + j) % 26]) {
                    count += j;
                    break;
                }
            }
        }

        cout << "Case #" << a << ": " << count << endl;
    }

    return 0;
}
