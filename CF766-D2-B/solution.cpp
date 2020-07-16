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

    vector<int> sides;
    int next;
    for(int i = 0; i < n; i++) {
        scanf("%d", &next);
        sides.push_back(next);
    }

    sort(sides.begin(), sides.end());

    for(int i = 0; i < n-2; i++) {
        if(sides[i] + sides[i+1] > sides[i+2]) {
            printf("YES\n");
            return 0;
        }
    }

    printf("NO\n");

    return 0;
}
