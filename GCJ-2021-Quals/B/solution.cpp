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
        int CJ_cost, JC_cost;
        string s;

        cin >> CJ_cost >> JC_cost >> s;

        int val[s.length()][2];

        val[0][0] = val[0][1] = 0;
        if (s[0] == 'C')
            val[0][1] = INT_MAX - 100;
        else if (s[0] == 'J')
            val[0][0] = INT_MAX - 100;

        for (int i = 1; i < s.length(); i++) {
            if (s[i] == '?') {
                val[i][0] = min(val[i - 1][0], val[i - 1][1] + JC_cost);
                val[i][1] = min(val[i - 1][0] + CJ_cost, val[i - 1][1]);
            } else if (s[i] == 'C') {
                val[i][1] = INT_MAX - 100;
                val[i][0] = min(val[i - 1][0], val[i - 1][1] + JC_cost);
            } else {
                val[i][0] = INT_MAX - 100;
                val[i][1] = min(val[i - 1][0] + CJ_cost, val[i - 1][1]);
            }
        }

        cout << "Case #" << a << ": "
             << min(val[s.length() - 1][0], val[s.length() - 1][1]) << endl;
    }

    return 0;
}
