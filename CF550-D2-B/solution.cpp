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
    int n, l, r, diff;
    scanf("%d %d %d %d", &n, &l, &r, &diff);

    vector<int> probs;
    int next;

    for(int i = 0; i < n; i++) {
        scanf("%d", &next);
        probs.push_back(next);
    }

    int counter = 0;

    for(int i = 3; i < (1 << n); i++) {
        int sum = 0;
        int min = INT_MAX;
        int max = INT_MIN;

        for(int j = 0; j < 15; j++) {
            if(i & (1 << j)) {
                sum += probs[j];
                if (min > probs[j]) min = probs[j];
                if (max < probs[j]) max = probs[j];
            }
        }

        if(l <= sum && sum <= r && max-min >= diff) {
            counter++;
        }
    }

    printf("%d\n", counter);

    return 0;
}
