#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define X real()
#define Y imag()
#define EPS 0.000000001
#define M_PI 3.14159265358979323846
#define CROSSPROD(a, b) (conj(a)*(b)).Y
#define DOTPROD(a, b) ((a).X*(b).X + (a).Y+(b).Y)
#define FASTIO ios::sync_with_stdio(false);

int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};

template <class T>
T gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

template <class T>
T modpow(T x, T n, T m) {
    if(n == 0) return 1 % m;
    ll u = modpow(x, n/2, m);
    u = (u*u)%m;
    if(n%2 == 1) u = (u*x)%m;
    return u;
}

int main () {
    FASTIO
    string s;
    unordered_map<char, int> dict;

    cin >> s;
    for(const auto& c: s) {
        if(dict.count(c)) dict[c]++;
        else dict.insert({c, 1});
    }

    int odd = 0;
    for(auto i = dict.begin(); i != dict.end(); i++) {
        if(i->second % 2 == 1) odd++;
    }

    if(odd % 2 == 0 && odd != 0) {
        printf("Second\n");
    } else {
        printf("First\n");
    } 

    return 0;
}
