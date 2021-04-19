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

template <class T>
bool prime(T n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    FASTIO
    int n;
    cin >> n;

    for (int a = 1; a <= n; a++) {
        ull val;
        cin >> val;

        ull root = sqrtl(val);
        ull factor1 = root, factor2, factor3;

        while (!prime<ull>(factor1)) factor1--;
        factor2 = factor1 - 1;
        factor3 = factor1 + 1;

        while (!prime<ull>(factor2)) factor2--;
        while (!prime<ull>(factor3)) factor3++;

        cout << "Case #" << a << ": ";
        factor1* factor3 > val ? cout << factor1 * factor2 << endl
                               : cout << factor1 * factor3 << endl;
    }

    return 0;
}
