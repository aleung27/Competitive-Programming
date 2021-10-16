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

bool isVowel(char c) {
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return true;
    return false;
}

bool isGungle(char c) {
    if (c == 'G' || c == 'L') return true;
    return false;
}

int main() {
    FASTIO
    string s;
    cin >> s;

    bool ok = true;
    for (int i = 0; i < s.length(); i++) {
        if (i == 0 && isVowel(s[i])) {
            ok = false;
            break;
        } else if (isVowel(s[i]) && !isGungle(s[i - 1])) {
            ok = false;
            break;
        }
    }

    if (ok)
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    return 0;
}
