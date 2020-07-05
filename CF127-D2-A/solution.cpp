#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define X real()
#define Y imag()
#define EPS 0.000000001
#define CROSSPROD(a, b) (conj(a)*b).Y

ull gcd(ull a, ull b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}


int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main () {
    int n, k;
    scanf("%d %d", &n, &k);

    complex<int> lastpt, nextpt;
    complex<double> pt;
    int x, y;
    scanf("%d %d", &x, &y);
    lastpt.real(x);
    lastpt.imag(y);

    long double dist = 0.0;

    for(int i = 1; i < n; i++) {
        scanf("%d %d", &x, &y);
        nextpt.real(x);
        nextpt.imag(y);

        pt.real(nextpt.X-lastpt.X);
        pt.imag(nextpt.Y-lastpt.Y);
        dist += sqrt(norm(pt));

        lastpt.real(nextpt.X);
        lastpt.imag(nextpt.Y);
    }

    dist *= k;
    dist /= 50;

    printf("%Lf\n", dist);


    return 0;
}
