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

ll solve(vector<bool>& arr) {
    ll count = 0;
    bool inSeq = false;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i]) {
            if (!inSeq) {
                inSeq = true;
                count++;
            }
        } else {
            inSeq = false;
        }
    }

    return count++;
}

int main() {
    FASTIO
    int t;
    cin >> t;
    map<char, vector<char>> colours;

    colours.insert({'U', {}});
    colours.insert({'R', {'R'}});
    colours.insert({'Y', {'Y'}});
    colours.insert({'B', {'B'}});
    colours.insert({'O', {'R', 'Y'}});
    colours.insert({'P', {'R', 'B'}});
    colours.insert({'G', {'Y', 'B'}});
    colours.insert({'A', {'R', 'Y', 'B'}});

    for (int a = 1; a <= t; a++) {
        int n;
        string s;
        cin >> n;
        cin >> s;

        vector<bool> red(n, 0);
        vector<bool> blue(n, 0);
        vector<bool> yellow(n, 0);

        for (int i = 0; i < n; i++) {
            for (const auto& c : colours[s[i]]) {
                if (c == 'R')
                    red[i] = true;
                else if (c == 'Y')
                    yellow[i] = true;
                else if (c == 'B')
                    blue[i] = true;
            }
        }

        ll count = 0;
        count += solve(red);
        count += solve(blue);
        count += solve(yellow);

        cout << "Case #" << a << ": " << count << endl;
    }

    return 0;
}
