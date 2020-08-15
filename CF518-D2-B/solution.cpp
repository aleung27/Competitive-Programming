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
    string s, t;
    cin >> s >> t;

    unordered_map<char, int> needs;
    unordered_map<char, int> has;

    for (const char& c : s) {
        if (needs.count(c))
            needs[c]++;
        else
            needs.insert({c, 1});
    }

    for (const char& c : t) {
        if (has.count(c))
            has[c]++;
        else
            has.insert({c, 1});
    }

    int yay = 0, whoops = 0;

    for (const auto p : needs) {
        if (has.count(p.first)) {
            int m = min(has[p.first], p.second);
            has[p.first] -= m;
            needs[p.first] -= m;
            yay += m;
        }
    }

    for (const auto p : needs) {
        if (isupper(p.first) && has.count(tolower(p.first))) {
            int m = min(has[tolower(p.first)], p.second);
            has[tolower(p.first)] -= m;
            needs[p.first] -= m;
            whoops += m;
        } else if (islower(p.first) && has.count(toupper(p.first))) {
            int m = min(has[toupper(p.first)], p.second);
            has[toupper(p.first)] -= m;
            needs[p.first] -= m;
            whoops += m;
        }
    }

    printf("%d %d\n", yay, whoops);

    return 0;
}
