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
        int n;
        string s;
        cin >> n >> s;

        map<pair<int, int>, int> map;
        pair<int, int> letters[n];
        int opt[n];

        // Preprocess count of D and K & insert into map
        letters[0] = s[0] == 'D' ? make_pair(1, 0) : make_pair(0, 1);
        map.insert({letters[0], 0});
        for (int i = 1; i < n; i++) {
            if (s[i] == 'D') {
                letters[i] = {letters[i - 1].first + 1, letters[i - 1].second};
            } else {
                letters[i] = {letters[i - 1].first, letters[i - 1].second + 1};
            }
            map.insert({letters[i], i});
        }

        opt[0] = 1;
        n == 1 ? cout << opt[0] << endl : cout << opt[0] << " ";
        for (int i = 1; i < n; i++) {
            if (letters[i].second == 0 || letters[i].first == 0)
                opt[i] = opt[i - 1] + 1;
            else {
                int d = letters[i].first, k = letters[i].second;
                bool done = false;
                if (d >= k) {
                    for (int j = k - 1; j > 0; j--) {
                        if ((d * j) % k == 0 && map.count({d * j / k, j})) {
                            opt[i] = 1 + opt[map[{d * j / k, j}]];
                            done = true;
                            break;
                        }
                    }
                } else {
                    for (int j = d - 1; j > 0; j--) {
                        if ((k * j) % d == 0 && map.count({j, k * j / d})) {
                            opt[i] = 1 + opt[map[{j, k * j / d}]];
                            done = true;
                            break;
                        }
                    }
                }
                if (!done) opt[i] = 1;
            }
            i == n - 1 ? cout << opt[i] << endl : cout << opt[i] << " ";
        }
    }

    return 0;
}
