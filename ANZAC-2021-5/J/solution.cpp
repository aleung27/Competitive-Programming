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
    FASTIO
    int n, l, p;

    cin >> n >> l >> p;
    vector<int> carriages(n, 0);

    int maxDist = -1, maxNum = -1, pos;
    for (int i = 0; i < p; i++) {
        cin >> pos;
        pos = n * l - pos;

        for (int j = 0; j < n; j++) {
            int left = j * l, right = (j + 1) * l;
            if ((left < pos || (j == 0 && left <= pos)) && pos <= right) {
                carriages[j]++;
                maxDist = max(maxDist, abs((left + right) / 2 - pos));
                break;
            }
        }
    }

    for (const auto& e : carriages)
        if (e > maxNum) maxNum = e;

    cout << maxDist << endl << maxNum << endl;

    return 0;
}
