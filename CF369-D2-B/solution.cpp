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
    int n, k, l, r, sumK, sumAll;
    scanf("%d %d %d %d %d %d", &n, &k, &l, &r, &sumAll, &sumK);

    vector<int> front;
    
    int amt = sumK/k;
    int diff = sumK - amt*k;
    for(int i = 0; i < k; i++) {
        front.push_back(amt);
        if(diff > 0) {
            front[i]++;
            diff--;
        }
    }

    if(n != k) {
        amt = (sumAll-sumK)/(n-k);
        diff = (sumAll-sumK) - amt*(n-k);

        for(int i = front.size(); i < n; i++) {
            front.push_back(amt);
            if(diff > 0) {
                front[i]++;
                diff--;
            }
        }
    }

    for(int i = 0; i < front.size(); i++) {
        i == front.size() - 1 ? printf("%d\n", front[i]) : printf("%d ", front[i]);
    }

    return 0;
}
