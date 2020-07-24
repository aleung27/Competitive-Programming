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

bool check (complex<int> coord, vector<pair<complex<int>, int>>& radiators) {
    for(const auto& a: radiators) {
        if(sqrt((a.first.X-coord.X)*(a.first.X-coord.X) + (a.first.Y-coord.Y)*(a.first.Y-coord.Y)) - a.second <= EPS) {
            return true;
        }
    }

    return false;
}

int main () {
    FASTIO
    int x, y;
    cin >> x >> y;
    complex<int> corner1(x, y);
    cin >> x >> y;
    complex<int> corner2(x, y);

    int n;
    vector<pair<complex<int>, int>> radiators;

    cin >> n;
    int r;
    for(int i = 0; i < n; i++) {
        cin >> x >> y >> r;
        radiators.push_back({complex<int>(x, y), r}); 
    }

    int counter = 0;
    for(int i = min(corner1.X, corner2.X); i <= max(corner1.X, corner2.X); i++) {
        if(!check(complex<int> (i, corner1.Y), radiators)) counter++;
        if(!check(complex<int> (i, corner2.Y), radiators)) counter++;
    }

    for(int i = min(corner1.Y, corner2.Y) + 1; i < max(corner1.Y, corner2.Y); i++) {
        if(!check(complex<int>(corner1.X, i), radiators)) counter++;
        if(!check(complex<int>(corner2.X, i), radiators)) counter++;
    }

    cout << counter << endl;


    return 0;
}
