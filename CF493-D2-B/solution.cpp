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
    int n,a;
    scanf("%d", &n);

    vector<int>first;
    vector<int>second;
    ll sumA = 0, sumB = 0;
    bool lastA = false;

    while(n--) {
        scanf("%d", &a);
        if(a > 0){
            first.push_back(a);
            sumA += a;
            lastA = true;
        } else {
            second.push_back(-1*a);
            sumB += -1*a;
            lastA = false;
        }
    }

    if(sumA > sumB) printf("first\n");
    else if (sumB > sumA) printf("second\n");
    else {
        for(int i = 0; i < min(first.size(), second.size()); i++) {
            if(first[i] > second[i]) {
                printf("first\n");
                return 0;
            } else if (second[i] > first[i]) {
                printf("second\n");
                return 0;
            }
        }

        if(first.size() > second.size()) printf("first\n");
        else if(second.size() > first.size()) printf("second\n");
        else {
            lastA ? printf("first\n") : printf("second\n");
        }
    }


    return 0;
}
