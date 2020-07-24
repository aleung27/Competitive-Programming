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
    int n, t;
    scanf("%d %d", &n, &t);

    int debts[101] = {0};
    int from, to, amt;
    for(int i = 0; i < t; i++) {
        scanf("%d %d %d", &from, &to, &amt);
        debts[from] -= amt;
        debts[to] += amt;
    }

    int val = 0;
    for(int i = 0; i < n+1; i++) {
        if(debts[i] > 0) val += debts[i];
    }

    printf("%d\n", val);

    return 0;
}
