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
    int t;
    cin >> t;

    while (t--) {
        int a, n, total = 0;
        vector<int> odds;
        cin >> n;
        int curr = n - 1;

        for (int i = 0; i < n; i++) {
            cin >> a;
            if (a % 2)
                odds.push_back(a);
            else {
                total += curr;
                curr--;
            }
        }

        for (int i = 0; i < odds.size(); i++) {
            for (int j = i + 1; j < odds.size(); j++) {
                if (gcd<int>(odds[i], odds[j]) > 1) total++;
            }
        }

        cout << total << endl;
    }

    return 0;
}
