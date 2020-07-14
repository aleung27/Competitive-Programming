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

int main () {
    int n, k;
    scanf("%d %d", &n, &k);

    vector<int> extras;
    ll total = 0;

    pair<int, int> next;
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &next.first, &next.second);
        total += min(next.first, next.second);
        next.first >= next.second ? extras.push_back(0) : extras.push_back(min(next.first, next.second-next.first));
    }

    sort(extras.begin(), extras.end(), std::greater<int>());
    for(int i = 0; i < k; i++) {
        total += extras[i];
    }

    printf("%lld\n", total);

    return 0;
}
