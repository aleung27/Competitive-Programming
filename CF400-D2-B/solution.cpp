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
    int n, m;
    cin >> n >> m;

    string row;
    unordered_set<int> vals;
    int g, s;
    for(int i = 0; i < n; i++) {
        cin >> row;
        for(int j = 0; j < m; j++) {
            if(row[j] == 'G') g = j;
            else if(row[j] == 'S') s = j;
        }

        if(s < g) {
            printf("-1\n");
            return 0;
        }

        if(s != g) vals.insert(s-g);
    }

    printf("%d\n", (int)vals.size());




    return 0;
}
