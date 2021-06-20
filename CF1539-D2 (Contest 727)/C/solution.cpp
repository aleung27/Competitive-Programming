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

struct node {
    ll minLvl, maxLvl;
};

int main() {
    FASTIO
    ll n, k, x;
    cin >> n >> k >> x;

    vector<ll> students;
    vector<node> groups;
    vector<ll> diffs;

    for (int i = 0; i < n; i++) {
        ll next;
        cin >> next;
        students.push_back(next);
    }

    sort(students.begin(), students.end());

    for (int i = 0; i < n; i++) {
        struct node next;
        next.minLvl = students[i];
        next.maxLvl = students[i];
        while (i + 1 != n) {
            if (students[i + 1] - students[i] <= x) {
                next.maxLvl = students[i + 1];
                i++;
            } else {
                break;
            }
        }

        groups.push_back(next);
    }

    for (int i = 1; i < groups.size(); i++) {
        ll difference = groups[i].minLvl - groups[i - 1].maxLvl;
        difference == difference / x* x ? diffs.push_back(difference / x - 1)
                                        : diffs.push_back(difference / x);
    }

    sort(diffs.begin(), diffs.end());

    ll total = groups.size();

    // cout << total << endl;
    // for (const auto& e : diffs) cout << e << " ";
    // cout << endl;

    for (int i = 0; i < diffs.size(); i++) {
        if (k - diffs[i] >= 0) {
            total--;
            k -= diffs[i];
        } else {
            break;
        }
    }

    cout << total << endl;

    return 0;
}
