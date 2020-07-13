#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define X real()
#define Y imag()
#define EPS 0.000000001
#define M_PI 3.14159265358979323846
#define CROSSPROD(a, b) (conj(a)*b).Y
#define FASTIO ios::sync_with_stdio(false);

template <class T>
T gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

ll modpow(ll a, ll p, ll m) {
    if(p == 0) return 1 % m;

    ll res = modpow(a, p/2, m);
    res = (res*res) % m;
    if(p % 2 == 1) res = (res*a) % m;
    return res;
}

int main () {
    ll a, p, m;

    while(scanf("%lld %lld %lld", &a, &p, &m) != EOF) {
        ll ans = modpow(a, p, m);
        printf("%lld\n", ans);
    }


    return 0;
}
