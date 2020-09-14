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
    int n, a, b;

    while(scanf("%d", &n) == 1) {
        if(n == 0) break;
        scanf("%d %d", &a, &b);

        int alive = n;
        map<ull, int> called;

        ull at = 0;
        while(1) {
            if(!called.count(at)) called.insert({at, 1});
            else{
                called[at]++;
                if(called[at] == 2) alive--;
                else if(called[at] == 3) break;
            }

            at = ((((ull)a % n)*modpow<ull>(at, 2, n)) % n + (ull)b) % (ull)n;
        }

        printf("%d\n", alive);
    } 
    return 0;
}
