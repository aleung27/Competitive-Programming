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
    int n, x, y;
    
    scanf("%d %d %d", &n, &x, &y);
    complex<int> gun(x, y);
    
    vector<double> gradients;
    double gradient;
    bool inf = false;

    for(int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        complex<int> pt(x, y);

        if(pt.X == gun.X) inf = true; 
        else {
            gradient = (double)(pt.Y-gun.Y)/(double)(pt.X-gun.X);
            gradients.push_back(gradient);
        }
    }

    sort(gradients.begin(), gradients.end());

    int count = 0;
    for(int i = 0; i < gradients.size(); i++) {
        if(i ==0) {
            count++;
        } else if(abs(gradients[i]-gradients[i-1]) > EPS) {
            count++;
        }
    }

    if(inf) count++;
    printf("%d\n", count);
    return 0;
}
