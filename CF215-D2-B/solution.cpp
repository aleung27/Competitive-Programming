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

int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};

template <class T>
T gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main () {
    int n, next;
    scanf("%d", &n);

    int r1 = INT_MIN;
    int p1 = INT_MIN;
    int p2 = INT_MAX;
    for(int i = 0; i < n; i++) {
        scanf("%d", &next);
        if(next > r1) r1 = next;
    }

    int m;
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d", &next);
        if(next > p1) p1 = next;
    }

    int k;
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        scanf("%d", &next);
        if(next < p2) p2 = next;
    }

    int a, b;
    scanf("%d %d", &a, &b);

    printf("%.10lf\n", sqrt(r1*r1*(double(b*p1)/double(a*p2 + b*p1))));

    return 0;
}
