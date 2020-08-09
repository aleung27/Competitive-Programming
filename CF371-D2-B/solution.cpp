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

template <typename T>
T gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b, a % b);
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
    int a, b;
    scanf("%d %d", &a, &b);

    int ans = gcd<int>(a, b);
    ll moves = 0;

    a /= ans;
    b /= ans;

    while (a != 1) {
        if (a % 5 == 0) {
            a /= 5;
            moves++;
        } else if (a % 3 == 0) {
            a /= 3;
            moves++;
        } else if (a % 2 == 0) {
            a /= 2;
            moves++;
        } else {
            break;
        }
    }

    while (b != 1) {
        if (b % 5 == 0) {
            b /= 5;
            moves++;
        } else if (b % 3 == 0) {
            b /= 3;
            moves++;
        } else if (b % 2 == 0) {
            b /= 2;
            moves++;
        } else {
            break;
        }
    }

    if (a != 1 || b != 1)
        printf("-1\n");
    else
        printf("%lld\n", moves);

    return 0;
}
