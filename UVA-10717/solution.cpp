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
    int n, t, a;

    while (scanf("%d %d", &n, &t) == 2) {
        if (!n && !t) break;

        vector<int> lengths;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a);
            lengths.push_back(a);
        }

        vector<int> lcms;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    for (int l = k + 1; l < n; l++) {
                        lcms.push_back(
                            lcm<int>(lcm<int>(lengths[i], lengths[j]),
                                     lcm<int>(lengths[k], lengths[l])));
                    }
                }
            }
        }

        for (int i = 0; i < t; i++) {
            scanf("%d", &a);
            int closestLess = -1, closestMore = INT_MAX;

            for (const auto& l : lcms) {
                int num = a / l;
                if (l * num == a) {
                    closestLess = closestMore = a;
                    break;
                } else {
                    if (closestLess < l * num) {
                        closestLess = l * num;
                    }
                    if (closestMore > l * (num + 1)) {
                        closestMore = l * (num + 1);
                    }
                }
            }

            printf("%d %d\n", closestLess, closestMore);
        }
    }

    return 0;
}
