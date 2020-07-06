#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define X real()
#define Y imag()
#define EPS 0.000000001
#define M_PI 3.14159265358979323846
#define CROSSPROD(a, b) (conj(a)*b).Y

template <class T>
T gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main () {
    int d, h, v, e;
    scanf("%d %d %d %d", &d, &h, &v, &e);

    double area = M_PI * ((double)d/2) * ((double)d/2);
    double rate = (double)v/area;

    if(rate < e) {
        printf("NO\n");
        return 0;
    }

    rate = rate - e;
    printf("YES\n%lf\n", (double)(h/rate));


    return 0;
}
