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

int queryupper(int heights[], int h, int n) {
    int left = 0, right = n-1;

    while (left <= right) {
        int mid = (left+right)/2;
        if(heights[mid] < h) left = mid + 1;
        else if (heights[mid] > h) right = mid - 1;
        else return mid;
    }
    
    if(left > n-1) return -1;
    else return max(left, right);
}

int querylower(int heights[], int h, int n) {
    int left = 0, right = n-1;

    while (left <= right) {
        int mid = (left+right)/2;
        if(heights[mid] < h) left = mid + 1;
        else if (heights[mid] > h) right = mid - 1;
        else return mid;
    }
    
    if(right < 0) return -1;
    else return min(left, right);
}

int main () {
    int n;
    scanf("%d", &n);

    int heights[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &heights[i]);
    }

    int q, h;
    scanf("%d", &q);
    for(int i = 0; i < q; i++) {
        scanf("%d", &h);
        int right = queryupper(heights, h+1, n);
        int left = querylower(heights, h-1, n);

        if(left == -1) printf("X %d\n", heights[right]);
        else if(right == -1) printf("%d X\n", heights[left]);
        else printf("%d %d\n", heights[left], heights[right]);
    }

    return 0;
}
