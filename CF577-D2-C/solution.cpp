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

map<int, int> primefactor(int n) {
    map<int, int> f;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            if (f.count(i) > 0)
                f[i]++;
            else
                f.insert({i, 1});
            n /= i;
        }
    }
    if (n > 1) {
        if (f.count(n) > 0) f[n]++;
        f.insert({n, 1});
    }
    return f;
}

int main() {
    int n;
    scanf("%d", &n);

    if (n == 1) {
        printf("0\n");
        return 0;
    }

    bool contains[n + 1];

    for (int i = 2; i <= n; i++) {
        contains[i] = false;

        map<int, int> pf = primefactor(i);
        if (pf.size() == 1) {
            contains[i] = true;
        }
    }

    int count = 0;
    for (int i = 2; i <= n; i++) {
        if (contains[i]) count++;
    }
    cout << count << endl;
    for (int i = 2; i <= n; i++) {
        if (contains[i]) {
            count--;
            cout << i;
            count ? cout << " " : cout << endl;
        }
    }

    return 0;
}
