#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define X real()
#define Y imag()
#define EPS 0.000000001
#define M_PI 3.14159265358979323846
#define CROSSPROD(a, b) (conj(a)*(b)).Y
#define DOTPROD(a, b) ((a).X*(b).X + (a).Y+(b).Y)
#define FASTIO ios::sync_with_stdio(false);

int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};

template <class T>
T gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

template <class T>
T modpow(T x, T n, T m) {
    if(n == 0) return 1 % m;
    ll u = modpow(x, n/2, m);
    u = (u*u)%m;
    if(n%2 == 1) u = (u*x)%m;
    return u;
}

int main () {
    int l, h, r;
    int maxR = INT_MIN;
    vector<int> heights(10005, 0);
    vector<int> ans;

    while(scanf("%d %d %d", &l, &h, &r) == 3) {
        for(int i = l; i < r; i++) {
            if(heights[i] < h)heights[i] = h; 
        }
        if(r > maxR) maxR = r;
    }

    for(int i = 1; i < r; i++) {
        if(heights[i] != heights[i-1]) {
            ans.push_back(i);
            ans.push_back(heights[i]);
        }   
    }

    ans.push_back(maxR);
    ans.push_back(0);
    for(int i = 0; i < ans.size(); i++) {
        i == ans.size() - 1 ? printf("%d\n", ans[i]) : printf("%d ", ans[i]);
    }

    return 0;
}
