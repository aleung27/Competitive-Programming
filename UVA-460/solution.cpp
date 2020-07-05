#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define X real()
#define Y imag()
#define EPS 0.000000001
#define CROSSPROD(a, b) (conj(a)*b).Y

template <class T>
T gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main () { 
    int n;
    int lx, ly, rx, ry;
    int lx2, ly2, rx2, ry2;
    scanf("%d", &n);

    for(; n > 0; n--) {
        scanf("%d %d %d %d", &lx, &ly, &rx, &ry);
        scanf("%d %d %d %d", &lx2, &ly2, &rx2, &ry2);

        vector<pair<int, bool>> xrange;
        vector<pair<int, bool>> yrange;

        xrange.push_back({lx, true});
        xrange.push_back({lx2, true});
        xrange.push_back({rx, false});
        xrange.push_back({rx2, false});

        yrange.push_back({ly, true});
        yrange.push_back({ly2, true});
        yrange.push_back({ry, false});
        yrange.push_back({ry2, false});

        sort(xrange.begin(), xrange.end());
        sort(yrange.begin(), yrange.end());

        int x1, x2, y1, y2;
        x1=x2=y1=y2=-1;
        if(xrange[1].second == true) {
            x1 = xrange[1].first;
            x2 = xrange[2].first;
        } 

        if(yrange[1].second == true) {
            y1 = yrange[1].first;
            y2 = yrange[2].first;
        } 

        if(x1 == -1 || y1 == -1) {
            printf("No Overlap\n");
        } else {
            printf("%d %d %d %d\n", x1, y1, x2, y2);
        }
        
        if(n != 1) printf("\n");

    }



    return 0;
}
