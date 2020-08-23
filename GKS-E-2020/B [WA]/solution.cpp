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
    int t, n, a, b, c;
    scanf("%d", &t);

    for (int cases = 1; cases <= t; cases++) {
        scanf("%d %d %d %d", &n, &a, &b, &c);

        if (a + b - c > n) {
            printf("Case #%d: IMPOSSIBLE\n", cases);
            continue;
        }

        a -= c;
        b -= c;
        if (a == 0 && b == 0 && c != n) {
            printf("Case #%d: IMPOSSIBLE\n", cases);
            continue;
        }

        vector<int> heights;
        if (n == 1) {
            heights.push_back(1);
        } else if (n == 2) {
            if (a == b) {
                heights.push_back(1);
                heights.push_back(1);
            } else if (a < b) {
                heights.push_back(2);
                heights.push_back(1);
            } else {
                heights.push_back(1);
                heights.push_back(2);
            }
        } else {
            for (int i = 0; i < a; i++) {
                heights.push_back(1);
            }

            for (int i = 0; i < c; i++) {
                heights.push_back(3);
            }

            for (int i = 0; i < (n - a - b - c); i++) {
                heights.push_back(1);
            }

            for (int i = 0; i < b; i++) {
                heights.push_back(2);
            }
        }

        printf("Case #%d: ", cases);
        for (int i = 0; i < heights.size(); i++) {
            i == heights.size() - 1 ? printf("%d\n", heights[i])
                                    : printf("%d ", heights[i]);
        }
    }

    return 0;
}
