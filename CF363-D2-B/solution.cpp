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

    vector<int> heights;
    int next;
    for(int i = 0 ; i < n; i++) {
        scanf("%d", &next);
        heights.push_back(next);
    }

    vector<int> sums;
    for(int i = 0 ; i < n; i++) {
        i == 0 ? sums.push_back(heights[0]) : sums.push_back(sums[i-1]+heights[i]);
    }

    pair<int, int> minim = {INT_MAX, -1};
    for(int i = 0; i <= n-k; i++) {
        if(sums[i+k-1]-sums[i]+heights[i] < minim.first) {
            minim = {sums[i+k-1]-sums[i]+heights[i], i+1};
        }
    }

    printf("%d\n", minim.second);

    return 0;
}
