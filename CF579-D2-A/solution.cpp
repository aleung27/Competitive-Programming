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
    int count = 0, x;

    scanf("%d", &x);

    while(x != 1) {
        if(x % 2 == 0) {
            x /= 2;
        } else {
            x = (x-1)/2;
            count++;
        }
    }


    printf("%d\n", ++count);

    return 0;
}
