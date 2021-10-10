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

bool same(double a, double b, double avg) {
    return abs(abs(a - avg) - abs(b - avg)) <= EPS;
}

int main() {
    FASTIO
    int t;
    cin >> t;

    while (t--) {
        int n, next;
        ll sum = 0;
        map<int, int> vals;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> next;
            if (vals.count(next))
                vals[next]++;
            else
                vals.insert({next, 1});

            sum += next;
        }

        vector<pair<int, int>> arr;
        for (const auto& e : vals) {
            arr.push_back(e);
        }

        double avg = (double)sum / (double)n;
        ll total = 0;

        int left = 0, right = arr.size() - 1;
        while (left < right) {
            if (same((double)arr[left].first, (double)arr[right].first, avg)) {
                total += (ll)arr[left].second * (ll)arr[right].second;
                left++;
                right--;
            } else {
                if (abs((double)arr[left].first - avg) >=
                    abs((double)arr[right].first - avg)) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        if (left == right && abs((double)arr[left].first - avg) <= EPS) {
            ll extra =
                ((ll)(arr[left].second) * (ll)(arr[left].second - 1)) / 2;
            total += extra;
        }

        cout << total << endl;
    }

    return 0;
}
