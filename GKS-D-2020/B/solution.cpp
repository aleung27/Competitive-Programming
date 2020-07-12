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
    int t, n;
    scanf("%d", &t);

    vector<int> vals;
    for(int c = 1; c <= t; c++) {
        scanf("%d", &n);
        vals.clear();

        int next;
        for(int i = 0; i < n; i++) {
            scanf("%d", &next);
            vals.push_back(next);
        }

        int up = 0, down = 0;
        int count = 0;
        for(int i = 1; i < n; i++) {
            if(vals[i] > vals[i-1]) {
                down = 0;
                up++;
            } else if(vals[i] < vals[i-1]) {
                up = 0;
                down++;
            }

            if(up == 4) {
                count++;
                up = 0;
            }
            if(down == 4) {
                count++;
                down = 0;
            }
        }

        printf("Case #%d: %d\n", c, count);
    }


    return 0;
}
