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

int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};

template <class T>
T gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main () {
    int n;
    scanf("%d", &n);

    vector<int> parts;
    int next;
    for(int i = 0; i < n; i++) {
        scanf("%d", &next);
        parts.push_back(next);
    }

    ll count = 1;
    bool found = false;
    for(int i = 0; i < n; i++) {
        if(parts[i]) {
            int row = 1, j = i+1;
            found = true;

            for(; j < n; j++) {
                if(j == n-1 && !parts[j]) row = 1;
                else if(!parts[j]) row++;
                else break;
            }
            i = j-1;
            count = (ll) count * row;
        }
    }

    found ? printf("%lld\n", count) : printf("0\n");


    return 0;
}
