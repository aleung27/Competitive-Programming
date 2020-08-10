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

ll total = 0;
ll n, m;

void generate_coms(vector<int>& elements) {
    for (int i = 1; i < (1 << m); i++) {
        ll currLcm = 1;
        int ones = 0;
        for (int j = 0; j < m; j++) {
            if (i & (1 << j)) {
                ones++;
                currLcm = lcm<ll>(currLcm, elements[j]);
            }
        }

        if (ones % 2 == 0) {
            total -= n / currLcm;
        } else {
            total += n / currLcm;
        }
    }
}

int main() {
    while (scanf("%lld %lld", &n, &m) == 2) {
        vector<int> elements;
        total = 0;
        int a;

        for (int i = 0; i < m; i++) {
            scanf("%d", &a);
            elements.push_back(a);
        }

        generate_coms(elements);
        printf("%lld\n", n - total);
    }

    return 0;
}
