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
    int n, index;
    scanf("%d %d", &n, &index);

    vector<bool> crims(n+1);
    int next;
    for(int i = 0; i < n; i++) {
        scanf("%d", &next);
        next == 1 ? crims[i+1] = true : crims[i+1] = false;
    }

    int total = 0;
    for(int i = 0; i < n; i++) {
        int left = index-i;
        int right = index+i;
        
        if(left <= 0 && right > n) break;

        if((left <= 0 && crims[right])|| (right > n && crims[left]) || (i == 0 && crims[index])) {
            total += 1;
        } else if(left > 0 && right <= n) {
            if(crims[left] && crims[right]) total += 2;
        }
    }

    printf("%d\n", total);
    return 0;
}
