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

int main () {
    int n;
    scanf("%d", &n);
    printf("INTERSECTING LINES OUTPUT\n");

    for(; n > 0; n--) {
        complex<double> pts[4];
        int x, y;
        for (int i = 0; i < 4; i++) {
            scanf("%d %d", &x, &y);
            pts[i].real((double)x);
            pts[i].imag((double)y);
        }

        // r == 1 - 0
        // s == 3 - 2
        // p == 0
        // q == 2
        /*
        Segments
        if(abs(CROSSPROD(pts[1]-pts[0], pts[3]-pts[2])) <= EPS && abs(CROSSPROD(pts[2]-pts[0], pts[1] - pts[0])) <= EPS) {
            double t0 = DOTPROD(pts[2]-pts[0], pts[1]-pts[0])/(DOTPROD(pts[1]-pts[0], pts[1]-pts[0]));
            double t1 = t0 + DOTPROD(pts[3]-pts[2], pts[1]-pts[0])/(DOTPROD(pts[1]-pts[0], pts[1]-pts[0]));

            if((0 <= t0 && t0 <= 1) || (0 <= t1 && t1 <= 1)) printf("LINE\n");
            else printf("NONE\n");

        } else if(abs(CROSSPROD(pts[1]-pts[0], pts[3]-pts[2])) <= EPS && abs(CROSSPROD(pts[2]-pts[0], pts[1] - pts[0])) > EPS) {
            printf("NONE\n");
        } else if(abs(CROSSPROD(pts[1]-pts[0], pts[3]-pts[2])) > EPS) {
            double t = CROSSPROD(pts[2]-pts[0], pts[3]-pts[2])/CROSSPROD(pts[1]-pts[0], pts[3]-pts[2]);
            double u = CROSSPROD(pts[2]-pts[0], pts[1]-pts[0])/CROSSPROD(pts[1]-pts[0], pts[3]-pts[2]);

            if(0 <= t && t <= 1 && 0 <= u && u <= 1) {
                printf("POINT %.2f %.2f\n", (pts[0]+t*(pts[1]-pts[0])).X, (pts[0]+t*(pts[1]-pts[0])).Y );
            } else {
                printf("NONE\n");
            }
        } else {
            printf("NONE\n");
        }

        */

        if(abs(CROSSPROD(pts[0]-pts[1], pts[0]-pts[2])) <= EPS && abs(CROSSPROD(pts[0]-pts[1], pts[0]-pts[3])) <= EPS) {
            printf("LINE\n");
        } else {
            double det = (pts[0].X-pts[1].X)*(pts[2].Y-pts[3].Y) - (pts[0].Y-pts[1].Y)*(pts[2].X-pts[3].X);
            if(abs(det) <= EPS) {
                printf("NONE\n");
            } else {
                double xcoord = (pts[0].X*pts[1].Y - pts[0].Y*pts[1].X)*(pts[2].X - pts[3].X) - (pts[0].X-pts[1].X)*(pts[2].X*pts[3].Y - pts[2].Y*pts[3].X);
                xcoord /= det;

                double ycoord = (pts[0].X*pts[1].Y - pts[0].Y*pts[1].X)*(pts[2].Y - pts[3].Y) - (pts[0].Y-pts[1].Y)*(pts[2].X*pts[3].Y - pts[2].Y*pts[3].X);
                ycoord /= det;

                printf("POINT %.2f %.2f\n", xcoord, ycoord);
            }
        }

    }

    printf("END OF OUTPUT\n");
    return 0;
}
