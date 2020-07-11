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

    pair<int, int> values[100005];
    int next;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &next);
        values[next] = {i, n-i+1};
    }

    int q;
    scanf("%d", &q);
    ll front = 0, back = 0;
    for(int i = 0; i< q; i++) {
        scanf("%d", &next);
        front += values[next].first;
        back += values[next].second;
    }

    cout << front << " " << back << endl;

    return 0;
}
