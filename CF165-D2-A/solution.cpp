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

int val(int v, int k) {
    int i = 0;
    int res = 0;
    while(v/(int)pow(k, i) > 0) {
        res += v/pow(k,i);
        i++;
    }
    return res;
}

int query(int n, int k) {
    int left = 1;
    int right = n;

    while(left <= right) {
        int mid = (left+right)/2;
        int res = val(mid, k);
        if(res > n) right = mid -1;
        else if(res < n) left = mid + 1;
        else return mid;
    }

    return max(left, right);
}

int main () {
    int n, k;
    scanf("%d %d", &n, &k);

    int index = query(n, k);
    printf("%d\n", index);

    return 0;
}
