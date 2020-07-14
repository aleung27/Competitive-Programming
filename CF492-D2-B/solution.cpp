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
    int lights, length;
    scanf("%d %d", &lights, &length);

    vector<int> pos;
    int next;
    for(int i = 0; i < lights; i++) {
        scanf("%d", &next);
        pos.push_back(next);
    }

    sort(pos.begin(), pos.end());

    double dist = DBL_MIN;
    for(int i = 0; i < lights-1; i ++) {
        if((double)(pos[i+1]-pos[i])/(double)2 > dist) dist = (double)(pos[i+1]-pos[i])/(double)2;
    }

    if((double)pos[0] > dist) dist = (double)pos[0];
    if((double)(length-pos[pos.size()-1]) > dist) dist = (double)(length-pos[pos.size()-1]);

    printf("%lf\n", dist);
    return 0;
}
