#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ull gcd(ull a, ull b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main () {
    ull l, r;
    scanf("%llu %llu", &l, &r);

    if (r-l < 2) {
        printf("-1\n");
        return 0;
    }

    for(ull i = 0; i <= r-l; i++) {
        for(ull j = i+1; j <= r-l; j++) {
            for(ull k= j+1; k <= r-l; k++) {
                if(i == j || j == k || i == k) continue;

                if(gcd(i + l, j + l) == 1 && gcd(j + l, k + l) == 1 && gcd(i + l, k + l) > 1) {
                    ull a[] = {i+l, j+l, k+l};
                    sort(a, a + 3);
                    printf("%llu %llu %llu\n", a[0], a[1], a[2]);
                    return 0;
                }
            }
        }
    }

    printf("-1\n");

    return 0;
}
