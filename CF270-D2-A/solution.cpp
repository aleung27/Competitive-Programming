#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define X real()
#define Y imag()
#define EPS 0.000000001
#define CROSSPROD(a, b) (conj(a)*b).Y

template <class T>
T gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main () {
    int n;
    scanf("%d", &n);

    int angle;
    for(; n > 0 ; n--){
        scanf("%d", &angle);
        int x = 2/(1-(double)angle/180) + EPS;
        if(180*(x-2) == angle*x) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
