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

bool cmp(pair<int, double>& a, pair<int, double>& b) {
    if(abs(a.second - b.second) <= EPS) return a.first < b.first;
    return a.second > b.second;
}

int main () {
    int n, t1, t2, k;
    scanf("%d %d %d %d", &n, &t1, &t2, &k);

    vector<pair<int,double>> res;
    int speed[2];
    for(int i = 1; i <= n; i++) {
        scanf("%d %d", &speed[0], &speed[1]);
        double best;

        if((double)(speed[0]*t1*(100-k))/100.0 + speed[1]*t2 > (double)(speed[1]*t1*(100-k))/100.0 + speed[0]*t2) {
            best = (double)(speed[0]*t1*(100-k))/100.0 + speed[1]*t2;
        } else {
            best = (double)(speed[1]*t1*(100-k))/100.0 + speed[0]*t2;
        }
        res.push_back({i, best});
    }

    sort(res.begin(), res.end(), cmp);

    for(const auto& a: res) {
        printf("%d %.2lf\n", a.first, a.second);
    }


    return 0;
}
