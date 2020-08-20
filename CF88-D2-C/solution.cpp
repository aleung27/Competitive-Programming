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
    int a, b;
    scanf("%d %d", &a, &b);
    bool swapped = false;

    if (a > b) {
        swap(a, b);
        swapped = true;
    }

    ll total = lcm<ll>(a, b);
    ll cnt = 0;

    ll curr = b;
    while (1) {
        if (curr % a)
            cnt += curr % a;
        else {
            cnt += a;
            break;
        }

        curr += b;
    }

    if (cnt * 2 == total) {
        printf("Equal\n");
    } else if (cnt * 2 > total) {
        swapped ? printf("Dasha\n") : printf("Masha\n");
    } else {
        swapped ? printf("Masha\n") : printf("Dasha\n");
    }

    return 0;
}
