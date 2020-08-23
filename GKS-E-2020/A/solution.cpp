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
    int t, n;
    scanf("%d", &t);

    for (int c = 1; c <= t; c++) {
        scanf("%d", &n);
        int arr[n];
        int diff = 0;
        int largest = INT_MIN;
        int cnt = 1;

        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        for (int i = 1; i < n; i++) {
            if (arr[i] - arr[i - 1] == diff)
                cnt++;
            else {
                if (cnt > largest) largest = cnt;
                diff = arr[i] - arr[i - 1];
                cnt = 2;
            }
        }

        if (cnt > largest) largest = cnt;
        printf("Case #%d: %d\n", c, largest);
    }

    return 0;
}
