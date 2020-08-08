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
T modpow(T x, T n, T m) {
    if (n == 0) return 1 % m;
    ll u = modpow(x, n / 2, m);
    u = (u * u) % m;
    if (n % 2 == 1) u = (u * x) % m;
    return u;
}

int main() {
    FASTIO
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<char> ans;
    for (const auto& c : s) {
        if (c == '1' || c == '0')
            continue;
        else if (c == '4') {
            ans.push_back('2');
            ans.push_back('2');
            ans.push_back('3');
        } else if (c == '6') {
            ans.push_back('3');
            ans.push_back('5');
        } else if (c == '8') {
            ans.push_back('2');
            ans.push_back('2');
            ans.push_back('2');
            ans.push_back('7');
        } else if (c == '9') {
            ans.push_back('3');
            ans.push_back('3');
            ans.push_back('2');
            ans.push_back('7');
        } else {
            ans.push_back(c);
        }
    }

    sort(ans.begin(), ans.end(), std::greater<char>());
    for (const auto& c : ans) {
        cout << c;
    }

    cout << endl;

    return 0;
}
