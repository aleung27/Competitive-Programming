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
    vector<int> a;
    vector<int> b;
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < max(n, m); i++){
        if(i < n) {
            a.push_back(i+1);
        }
        if(i < m) {
            b.push_back(i+1);
        }
    }

    ll counter = 0;
    for(int i = 0; i < n; i++) {
        int first = -1;
        for(int j = 0; j < m; j++) {
            if((a[i] + b[j]) % 5 == 0) {
                first = j;
                break;
            }
        }

        if(first == -1) continue;

        counter += (m-1-first)/5 + 1;
    }

    printf("%lld\n", counter);

    return 0;
}
