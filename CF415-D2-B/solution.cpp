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

double calc(ll at, int a, int b) {
    return double(at)*double(a)/double(b);
} 

int search(int x, ll max, int a, int b) {
    ll left = 0, right = x;

    while(left <= right) {
        ll mid = (left+right)/2;
        //printf("MID calc: %lld %lf\n", mid, calc(mid, a, b));
        if(calc(mid, a, b) < max) left = mid + 1;
        else if (calc(mid,a,b) > max) right = mid -1;
        else return mid;
    }

    return std::max(left, right);
}

int main () {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);

    int x;
    while(n--) {
        scanf("%d", &x);
        ll max = calc(x,a,b);
       // printf("%lld\n", max);

        if(a > b) printf("0");
        else printf("%d", x-search(x,max,a,b));

        n == 0 ? printf("\n") : printf(" ");
    }


    return 0;
}
