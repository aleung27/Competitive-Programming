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

bool mysort(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first == b.first) {
        return a.second < b.second;
    } else
        return a.first < b.first;
}

int main() {
    FASTIO
    int t, n, k;
    cin >> t;

    while (t--) {
        cin >> n >> k;
        char c;
        vector<pair<int, int>> ls;

        for (int i = 0; i < n; i++) {
            cin >> c;
            ls.push_back({c - '0', i});
        }

        sort(ls.begin(), ls.end(), mysort);

        ll total = n * n;
        ll valid = 0;

        // First val is the number, second is the items index in ls
        int start = INT_MIN, counter = 0;
        for (int i = 0; i < n; i++) {
            if (ls[i].first != 1) continue;
            counter++;

            if (start == INT_MIN) start = i;

            while (ls[i].second - ls[start].second > k) {
                start++;
            }

            valid += 2 * (i - start);
        }

        valid += counter;

        if (valid == 0)
            cout << "0/1" << endl;
        else {
            while (1) {
                bool done = true;
                for (int i = 2; i * i <= total; i++) {
                    if ((valid / i) * i == valid && (total / i) * i == total) {
                        valid /= i;
                        total /= i;
                        done = false;
                        break;
                    }
                }
                if (done) break;
            }
            if (valid == total)
                cout << "1/1" << endl;
            else
                cout << valid << "/" << total << endl;
        }
    }

    return 0;
}
