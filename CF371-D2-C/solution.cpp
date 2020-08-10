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
T modpow(T x, T n, T m) {
    if (n == 0) return 1 % m;
    ll u = modpow(x, n / 2, m);
    u = (u * u) % m;
    if (n % 2 == 1) u = (u * x) % m;
    return u;
}

int main() {
    FASTIO
    string s;
    cin >> s;

    int needs[3] = {0};  // 0 = B, 1 = S, 2 = C
    int have[3], prices[3];
    ll money, burgers = 0;

    for (const auto& c : s) {
        c == 'B' ? needs[0]++ : (c == 'S' ? needs[1]++ : needs[2]++);
    }

    cin >> have[0] >> have[1] >> have[2];
    cin >> prices[0] >> prices[1] >> prices[2];
    cin >> money;

    while (have[0] >= needs[0] && have[1] >= needs[1] && have[2] >= needs[2]) {
        burgers++;
        have[0] -= needs[0];
        have[1] -= needs[1];
        have[2] -= needs[2];
    }

    while ((needs[0] && have[0] != 0) || (needs[1] && have[1] != 0) ||
           (needs[2] && have[2] != 0)) {
        for (int i = 0; i < 3; i++) {
            if (have[i] < needs[i]) {
                money -= prices[i] * (needs[i] - have[i]);
                have[i] = needs[i];
            }

            if (money < 0) {
                cout << burgers << endl;
                return 0;
            }
        }

        have[0] -= needs[0];
        have[1] -= needs[1];
        have[2] -= needs[2];
        burgers++;
    }

    ll cost =
        needs[0] * prices[0] + needs[1] * prices[1] + needs[2] * prices[2];
    burgers += money / cost;

    cout << burgers << endl;

    return 0;
}
