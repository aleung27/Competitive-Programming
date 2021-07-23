#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define X real()
#define Y imag()
#define EPS 0.0000001
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

double total = 0.0;
double v;

void solve(double c, double m, double p, double prob, int races) {
    total += races * prob * p;
    // cout << c << " " << m << " " << p << " " << prob << "Added "
    //      << prob * p * races << endl;

    if (c > EPS) {
        if (c > v) {
            if (m > EPS)
                solve(c - v, m + v / 2, p + v / 2, prob * c, races + 1);
            else
                solve(c - v, m, p + v, prob * c, races + 1);
        } else if (c <= v) {
            if (m > EPS)
                solve(DBL_MIN, m + c / 2, p + c / 2, prob * c, races + 1);
            else
                solve(DBL_MIN, m, p + c, prob * c, races + 1);
        }
    }

    if (m > EPS) {
        if (m > v) {
            if (c > EPS)
                solve(c + v / 2, m - v, p + v / 2, prob * m, races + 1);
            else
                solve(c, m - v, p + v, prob * m, races + 1);
        } else if (m <= v) {
            if (c > EPS)
                solve(c + m / 2, DBL_MIN, p + m / 2, prob * m, races + 1);
            else
                solve(c, DBL_MIN, p + m, prob * m, races + 1);
        }
    }
}

int main() {
    FASTIO
    int t;
    cin >> t;

    while (t--) {
        double c, m, p;
        cin >> c >> m >> p >> v;

        total = 0.0;

        solve(c, m, p, 1.0, 1);

        cout << setprecision(10) << total << endl;
    }

    return 0;
}
