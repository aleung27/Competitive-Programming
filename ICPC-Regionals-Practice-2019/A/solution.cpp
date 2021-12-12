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
    int n;
    int aMin, aMax, bMin, bMax;

    cin >> n >> aMin >> aMax >> bMin >> bMax;

    int aTotal = 0, bTotal = 0;
    int extra = 0;
    for (int i = 0; i < n; i++) {
        int next;
        cin >> next;

        aTotal += next / 2;
        bTotal += next / 2;

        if (next % 2) extra++;
    }

    if (aTotal < aMin) {
        if (extra - (aMin - aTotal) >= 0) {
            extra -= aMin - aTotal;
            aTotal = aMin;
        } else {
            cout << "No" << endl;
            return 0;
        }
    }

    if (bTotal < bMin) {
        if (extra - (bMin - bTotal) >= 0) {
            extra -= bMin - bTotal;
            bTotal = bMin;
        } else {
            cout << "No" << endl;
            return 0;
        }
    }

    if (aTotal > aMax || bTotal > bMax) {
        cout << "No" << endl;
        return 0;
    }

    if (extra && extra > aMax - aTotal + bMax - bTotal) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;

    return 0;
}
