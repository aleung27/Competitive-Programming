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

long double compute(int n, int r) {
    long double result = 1;
    vector<double> fracs;

    int counter = 0;
    for(int i = n; i >= n-r+1; i--) {
        if(r-counter == 0) {
            for(int j = i; j >= n-r+1; j--) {
                result *= j;
            }
            break;
        } else {
            fracs.push_back((double)i/(double)(r-counter));
            counter++;
        }
    }

    for(const auto& val: fracs) {
        result *= val;
    }

    return result;
}

int main () {
    int n, r;

    while(scanf("%d %d", &n, &r)) {
        if(n == 0 && r == 0) break;

        long double combinations = compute(n, r);
        printf("%d things taken %d at a time is %lld exactly.\n", n, r, (ll)(combinations + 10000*EPS));
    }


    return 0;
}
