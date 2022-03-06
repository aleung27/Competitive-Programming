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
    int t;
    cin >> t;

    while (t--) {
        int n, c;
        cin >> n >> c;

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());

        if (arr[0] != 1) {
            cout << "No" << endl;
            continue;
        }

        if (n == 1 || n == 2) {
            cout << "Yes" << endl;
            continue;
        }

        set<int> seen;
        seen.insert(arr[0]);
        seen.insert(arr[1]);

        int factor = arr[1] / arr[0];
        bool isOk = true;
        bool factoring = true;

        for (int i = 2; i < n; i++) {
            if (seen.count(arr[i])) continue;
            seen.insert(arr[i]);

            if (arr[i - 1] * factor == arr[i] && factoring) {
                continue;
            } else {
                bool isValid = true;
                factoring = false;
                for (int j = 0; j < i; j++) {
                    if (!seen.count(arr[i] / arr[j])) {
                        isValid = false;
                        break;
                    }
                }
                if (!isValid) {
                    isOk = false;
                    break;
                }
            }
        }

        if (isOk)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}
