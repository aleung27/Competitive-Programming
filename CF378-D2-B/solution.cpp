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
    int n;
    scanf("%d", &n);

    bool q1[n], q2[n];
    int first[n], second[n];

    memset(q1, false, n * sizeof(bool));
    memset(q2, false, n * sizeof(bool));
    memset(q1, true, n / 2 * sizeof(bool));
    memset(q2, true, n / 2 * sizeof(bool));

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &first[i], &second[i]);
    }

    int atFirst = 0, atSecond = 0;
    for (int i = 0; i < n; i++) {
        if (first[atFirst] < second[atSecond]) {
            q1[atFirst] = true;
            atFirst++;
        } else {
            q2[atSecond] = true;
            atSecond++;
        }
    }

    for (int i = 0; i < n; i++) {
        q1[i] ? printf("1") : printf("0");
    }

    printf("\n");
    for (int i = 0; i < n; i++) {
        q2[i] ? printf("1") : printf("0");
    }
    printf("\n");

    return 0;
}
