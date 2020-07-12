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
    int n;
    scanf("%d", &n);

    char colours[8] = {'R', 'O', 'Y', 'G', 'B', 'I', 'V' , '\0'};

    printf("%s", colours);
    n -= 7;

    int i = 0;
    while(n != 0) {
        printf("%c", colours[3+(i%4)]);
        i++;
        n--;
    }

    printf("\n");

    return 0;
}
