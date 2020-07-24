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

int check(int num) {
    int count = 0;
    if((int)sqrt(num)*(int)sqrt(num) == num) count++;

    for(int i = 1; i < sqrt(num) - EPS; i++) {
        if(num % i == 0) count += 2;
    }

    return count;
}

int main () {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    ll sum = 0;
    for(int i = 1; i <= a; i++) {
        for(int j = 1; j <= b; j++) {
            for(int k = 1; k <= c; k++) {
                sum = (sum + check(i*j*k)) % (1073741824);
            }
        }
    }

    printf("%lld\n", sum);

    return 0;
}
