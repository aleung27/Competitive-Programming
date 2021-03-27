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

int reversort(vector<int> arr) {
    int ans = 0;

    for (int i = 0; i < arr.size() - 1; i++) {
        pair<int, int> min = {0, INT_MAX};
        for (int j = i; j < arr.size(); j++) {
            if (arr[j] < min.second) {
                min = {j, arr[j]};
            }
        }
        ans += min.first - i + 1;
        reverse(arr.begin() + i, arr.begin() + min.first + 1);
    }

    return ans;
}

int main() {
    FASTIO
    int t;
    cin >> t;

    for (int a = 1; a <= t; a++) {
        int n, c;
        cin >> n >> c;

        vector<int> arr;
        for (int i = 0; i < n; i++) arr.push_back(i + 1);
        bool done = false;

        do {
            if (reversort(arr) == c) {
                cout << "Case #" << a << ": ";
                for (int i = 0; i < n; i++) {
                    cout << arr[i];
                    i != n - 1 ? cout << " " : cout << endl;
                }

                done = true;
                break;
            }
        } while (next_permutation(arr.begin(), arr.end()));

        if (!done) cout << "Case #" << a << ": IMPOSSIBLE" << endl;
    }

    return 0;
}
