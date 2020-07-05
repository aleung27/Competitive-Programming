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
    vector<pair<complex<double>, complex<double>>> rects;

    double lx, ly, rx, ry;
    char next;
    while(1) {
        scanf(" %c", &next);
        if(next == '*') break;

        scanf("%lf %lf %lf %lf", &lx, &ly, &rx, &ry);
        complex<double> left(lx, ly);
        complex<double> right(rx, ry);
        rects.push_back({left, right});
    }

    double x, y;
    int counter = 1;
    bool found = false;
    while(1) {
        found = false;
        scanf("%lf %lf", &x, &y);
        if (abs(x-9999.9) <= EPS && abs(y-9999.9) <= EPS) break;

        for(int i = 0; i < rects.size(); i++) {
            if(x > rects[i].first.X && x < rects[i].second.X && y < rects[i].first.Y && y > rects[i].second.Y) {
                printf("Point %d is contained in figure %d\n", counter, i+1);
                found = true;
            }
        }

        if(!found) printf("Point %d is not contained in any figure\n", counter);
        counter++;
    }

    return 0;
}
