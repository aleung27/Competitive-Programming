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
    int n, a, b;
    scanf("%d", &n);

    vector<int> eggs;
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        eggs.push_back(a);
    }

    int diff = 0;
    char vals[n];

    for(int i = 0; i < eggs.size(); i++) {
        if(abs(diff + eggs[i]) > abs(diff-1000+eggs[i])) {
            diff = diff-1000+eggs[i];
            vals[i] = 'G';
        } else {
            diff += eggs[i];
            vals[i] = 'A';
        }
    }

    if(diff > 500) printf("-1\n");
    else {
        for(const auto& c: vals) {
            printf("%c", c);
        }
        printf("\n");
    }


    return 0;
}
