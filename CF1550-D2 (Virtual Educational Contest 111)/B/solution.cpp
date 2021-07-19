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
        int n, a, b;
        string s;
        cin >> n >> a >> b;
        cin >> s;

        int score = 0;

        if (b >= 0) {
            score = (a + b) * n;
        } else {
            vector<pair<int, int>> pos;
            int last = -1;
            for (int i = 0; i < n; i++) {
                if (s[i] == last) {
                    pos.back().second++;
                } else {
                    pos.push_back({i, 1});
                    last = s[i];
                }
            }

            int l, r;
            l = r = pos.size() / 2;
            while (r < pos.size()) {
                if (l == r)
                    score += a * pos[l].second + b;
                else {
                    score += a * (pos[l].second + pos[r].second) + b;
                }
                l--;
                r++;
            }

            if (pos.size() % 2 == 0) score += a * pos[0].second + b;
        }

        cout << score << endl;
    }

    return 0;
}
