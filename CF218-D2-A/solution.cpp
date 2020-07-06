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
    int n, k;
    scanf("%d %d", &n, &k);

    vector<int> heights(1, -1);
    int next;
    for(int i = 0; i < 2*n + 1; i++) {
        scanf("%d", &next);
        heights.push_back(next);
    }

    for(int i = 1; i <= 2*n+1; i++) {
        if(i % 2 == 0 && heights[i-1] + 1 < heights[i] && heights[i + 1] + 1 < heights[i]) {
            k--;
            heights[i]--;
            if(k == 0) break;
        }
    }

    for(int i = 1; i <= 2*n+1; i++) {
        i == 2*n + 1 ? printf("%d\n", heights[i]) : printf("%d ", heights[i]);
    }

    return 0;
}
