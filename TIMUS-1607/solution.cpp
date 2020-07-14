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

int main () {
    int p, t, raise, lower;
    scanf("%d %d %d %d", &p, &raise, &t, &lower);

    if(p >= t) {
        printf("%d\n", p);
        return 0;
    }

    while(t-p > raise+lower) {
        p += raise;
        t -= lower;
    }

    p += raise;
    if(p > t) printf("%d\n", t);
    else {
        printf("%d\n", p);
    }

    return 0;
}
