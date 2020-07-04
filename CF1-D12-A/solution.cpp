#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main () {
    ll n, m, a;
    scanf("%lld %lld %lld", &n, &m, &a);

    printf("%lld\n", (ll)ceil((double)n/a)*(ll)ceil((double)m/a));


    return 0;
}
