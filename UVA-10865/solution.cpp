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
    while(1) {
        int n;
        scanf("%d", &n);
        if(!n) break;

        vector<complex<int>> pts;
        complex<int> center;

        int a, b;
        for(int i = 0; i < n; i++) {
            scanf("%d %d", &a, &b);
            complex<int> next(a, b);

            if(i == n/2) center = next;
            else pts.push_back(next);
        }

        int stan = 0, ollie = 0; 

        for(int i = 0; i < n-1; i++) {
            if(pts[i].X == center.X || pts[i].Y == center.Y) continue;
            if(pts[i].X > center.X && pts[i].Y > center.Y) stan++;
            else if(pts[i].X > center.X && pts[i].Y < center.Y) ollie++;
            else if(pts[i].X < center.X && pts[i].Y > center.Y) ollie++;
            else if(pts[i].X < center.X && pts[i].Y < center.Y) stan++;
        }

        printf("%d %d\n", stan, ollie);
    }


    return 0;
}
