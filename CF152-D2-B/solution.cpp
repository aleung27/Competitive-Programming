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
    FASTIO
    int l, w;
    cin >> w >> l;

    pair<int, int> pos;
    cin >> pos.first >> pos.second;

    int k;
    cin >> k;

    pair<int, int> vec;
    ll steps = 0;
    for(int i = 0; i < k; i++) {
        cin >> vec.first >> vec.second;
        int maxX = INT_MAX, maxY = INT_MAX;

        if(vec.first > 0) maxX = (w-pos.first)/vec.first;
        else if(vec.first < 0) maxX = (1-pos.first)/vec.first;

        if(vec.second > 0) maxY = (l-pos.second)/vec.second;
        else if(vec.second < 0) maxY = (1-pos.second)/vec.second;

        int maxStep = min(maxX, maxY);
        steps += maxStep;
        pos.first += maxStep*vec.first;
        pos.second += maxStep*vec.second;
    }

    cout << steps << endl;

    return 0;
}
