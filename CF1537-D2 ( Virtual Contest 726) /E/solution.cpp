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
    int n, k;
    string input;

    cin >> n >> k;
    cin >> input;

    string opt[k + 1];
    opt[1] = input[0];

    for (int i = 2; i <= k; i++) {
        string best;
        for (int j = 1; j <= n && i - j > 0; j++) {
            string curr = opt[i - j] + opt[j];
            if (j == 1)
                best = curr;
            else if (best > curr)
                best = curr;
        }

        opt[i] = best;
        if (i <= n && input.substr(0, i) < opt[i]) {
            opt[i] = input.substr(0, i);
        }
    }

    cout << opt[k] << endl;

    return 0;
}
