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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int t = 1; t <= n; t++) {
        map<char, int> chars;
        int vowels = 0, cons = 0;
        string s;

        cin >> s;

        for (const auto& c : s) {
            if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
                vowels++;
            else
                cons++;

            if (chars.count(c))
                chars.at(c)++;
            else
                chars.insert({c, 1});
        }

        int ans = INT_MAX;
        for (const auto& e : chars) {
            if (e.first == 'A' || e.first == 'E' || e.first == 'I' ||
                e.first == 'O' || e.first == 'U') {
                ans = min(ans, cons + 2 * (vowels - e.second));
            } else {
                ans = min(ans, vowels + 2 * (cons - e.second));
            }
        }

        if (vowels == 0 || cons == 0) ans = min(ans, (int)s.length());
        cout << "Case #" << t << ": " << ans << endl;
    }

    return 0;
}
