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
    while(1) {
        complex<double> pts[4];
        double x, y;

        if(scanf("%lf %lf", &x, &y) == EOF) break;
        pts[0].real(x);
        pts[0].imag(y);

        for(int i = 1; i < 4; i++) {
            scanf("%lf %lf", &x, &y);
            pts[i].real(x);
            pts[i].imag(y);
        }

        complex<double> vec[2];
        for(int i = 0; i < 2; i++) {
            for(int j = 2; j < 4; j++) {
                if(pts[i] == pts[j]) {
                    vec[0] = pts[(i+1) % 2] - pts[i];
                    vec[1] = pts[(j+1) % 2 + 2] - pts[j];
                    
                    complex<double> ans;
                    ans = pts[i] + vec[0] + vec[1];
                    printf("%.3lf %.3lf\n", ans.X, ans.Y);

                }
            }
        }
    }


    return 0;
}
