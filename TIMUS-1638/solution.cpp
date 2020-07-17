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
    int book, cover, start, end;
    scanf("%d %d %d %d", &book, &cover, &start, &end);

    int dist = 0;
    if(end > start) {
        dist += 2*(end-start)*cover + (end-start-1)*book;
    } else if(start == end) {
        dist = book;
    } else {
        dist += 2*(start-end)*cover + (start-end+1)*book;
    }

    printf("%d\n", dist);

    return 0;
}
