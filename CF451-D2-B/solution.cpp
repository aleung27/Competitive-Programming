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

    vector<int> orig;
    vector<int> sorted;
    int next;
    for(int i = 0; i < n; i++) {
        scanf("%d", &next);
        orig.push_back(next);
        sorted.push_back(next);
    }

    sort(sorted.begin(), sorted.end());
    if(sorted == orig) {
        printf("yes\n1 1\n");
        return 0;
    }
    int start, end;

    for(int i = 0; i < n; i++) {
        if(orig[i] != sorted[i]) {
            start = i;
            break;
        }
    }

    for(int i = n-1; i >= 0; i--) {
        if(orig[i] != sorted[i]) {
            end = i;
            break;
        }
    }


    reverse(orig.begin()+start, orig.begin()+end+1);

    orig == sorted ? printf("yes\n%d %d\n", start+1, end+1) : printf("no\n");

    return 0;
}
