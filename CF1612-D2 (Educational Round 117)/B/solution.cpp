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
        cin >> n >> a >> b;

        if (a > n / 2 + 1 || b < n / 2 - 1) {
            cout << "-1" << endl;
            continue;
        }

        bool taken[n + 1];
        memset(taken, 0, sizeof(bool) * (n + 1));

        vector<int> left, right;
        left.push_back(a);
        right.push_back(b);
        taken[a] = true;
        taken[b] = true;

        int largest = n;
        int smallest = 1;

        bool ok = true;

        for (int i = 1; i < n / 2; i++) {
            while (taken[largest]) largest--;

            if (largest < a) {
                ok = false;
                break;
            } else {
                left.push_back(largest);
                taken[largest--] = true;
            }
        }

        if (!ok) {
            cout << "-1" << endl;
            continue;
        }

        for (int i = 1; i < n / 2; i++) {
            while (taken[smallest]) smallest++;

            if (smallest > b) {
                ok = false;
                break;
            } else {
                right.push_back(smallest);
                taken[smallest++] = true;
            }
        }

        if (!ok) {
            cout << "-1" << endl;
            continue;
        }

        for (const auto& e : left) cout << e << " ";
        for (int i = 0; i < right.size(); i++) {
            cout << right[i];
            if (i == right.size() - 1)
                cout << endl;
            else
                cout << " ";
        }
    }

    return 0;
}
