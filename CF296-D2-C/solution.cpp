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

struct op {
    int l, r, amnt;
};

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    op operations[m];
    for (int i = 0; i < m; i++) {
        op next;
        scanf("%d %d %d", &next.l, &next.r, &next.amnt);
        next.l--;
        next.r--;
        operations[i] = next;
    }

    int applications[m];
    memset(applications, 0, m * sizeof(int));
    for (int i = 0; i < k; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        applications[l - 1]++;
        if (r != m) applications[r]--;
    }

    for (int i = 0; i < m; i++) {
        if (i) applications[i] += applications[i - 1];
    }

    ll additions[n];
    memset(additions, 0, n * sizeof(ll));
    for (int i = 0; i < m; i++) {
        ll amnt = (ll)applications[i] * (ll)operations[i].amnt;
        additions[operations[i].l] += amnt;
        if ((operations[i].r + 1) != n) additions[operations[i].r + 1] -= amnt;
    }

    for (int i = 0; i < n; i++) {
        if (i) additions[i] += additions[i - 1];
    }

    for (int i = 0; i < n; i++) {
        i == n - 1 ? printf("%lld\n", additions[i] + (ll)arr[i])
                   : printf("%lld ", additions[i] + (ll)arr[i]);
    }

    return 0;
}
