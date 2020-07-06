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
    int r1, r2, c1, c2, d1, d2;
    scanf("%d %d %d %d %d %d", &r1, &r2, &c1, &c2, &d1, &d2);

    int s11, s12, s21, s22;
    for(int i = 1; i <= 9; i++) {
        for(int j = 1; j <= 9; j++) {
            for(int k = 1; k <= 9; k++) {
                for(int l = 1; l <= 9; l++) {
                    if(i != j && i != k && i != l && j != k && j != l && k != l) {
                        s11 = i;
                        s12 = j;
                        s21 = k;
                        s22 = l;

                        if(s11+s21 == c1 && s12 + s22 == c2 && s11 + s22 == d1 && s12 + s21 == d2 && s11 + s12 == r1 && s21 + s22 == r2) {
                            printf("%d %d\n%d %d\n", s11, s12, s21, s22);
                            return 0;
                        }
                    }
                }
            }
        }
    }

    printf("-1\n");


    return 0;
}
