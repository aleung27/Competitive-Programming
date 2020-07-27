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
    double w, x, y;
    scanf("%lf %lf %lf", &w, &x, &y);
    
    // 1st square
    if(-1*w/2 < x && x < w/2 && y < w && y > 0) {
        printf("1\n");
        return 0;
    }

    if((int)y % (int)w == 0) {
        printf("-1\n");
        return 0;
    }

    double squares = y/w;
    int intSquares = squares + EPS;

    if(intSquares == 0) {

    } else if(intSquares % 2 == 0) {
        if(-1*w < x && x < 0) {
            //left 
            printf("%d\n", (intSquares)+(intSquares-1)/2+1);
            return 0;
        } else if (x > 0 && x < w) {
            //right
            printf("%d\n", (intSquares)+(intSquares-1)/2+2);
            return 0;
        }
    } else {
        if(-1*w/2 < x && x < w/2 && abs(y-intSquares*w) > EPS) {
            //Square
            printf("%d\n", (intSquares)+(intSquares-1)/2+1);
            return 0;
        }
    }

    printf("-1\n");

    return 0;
}
