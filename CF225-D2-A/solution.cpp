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
    int n;
    scanf("%d", &n);

    int top;
    scanf("%d", &top);
    pair<int, int> side;

    side.first = top;
    side.second = 7 - top;

    int a, b;
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        if(i == 0) continue;

        if(a == side.first || a == side.second || b == side.first || b == side.second) {
            printf("NO\n");
            return 0;
        }
    }

    printf("YES\n");

    return 0;
}
