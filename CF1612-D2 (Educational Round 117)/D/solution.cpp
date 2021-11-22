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
        ll a, b, x;
        cin >> a >> b >> x;

        if (x > a && x > b) {
            cout << "NO" << endl;
            continue;
        }

        set<pair<ll, ll>> seen;
        queue<pair<ll, ll>> q;
        q.push({min(a, b), max(a, b)});

        bool done = false;
        while (!q.empty()) {
            auto at = q.front();
            q.pop();
            seen.insert(at);
            cout << at.first << " " << at.second << endl;

            if (at.first == x || at.second == x) {
                done = true;
                break;
            } else {
                ll diff = abs(at.first - at.second);
                pair<ll, ll> choice1 = {min(at.first, diff),
                                        max(at.first, diff)};
                pair<ll, ll> choice2 = {min(at.second, diff),
                                        max(at.second, diff)};

                if (!seen.count(choice1)) {
                    seen.insert(choice1);
                    q.push(choice1);
                }

                if (!seen.count(choice2)) {
                    seen.insert(choice2);
                    q.push(choice2);
                }
            }
        }

        done ? cout << "YES" << endl : cout << "NO" << endl;
    }

    return 0;
}
