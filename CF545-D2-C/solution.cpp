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

#define LEFT 0
#define RIGHT 1
#define NEITHER 2

int main () {
    int t;
    scanf("%d", &t);

    int table[3][t];
    vector<pair<int, int>> vals;

    int pos, height;
    for(int i = 0; i < t; i++) {
        scanf("%d %d", &pos, &height);
        vals.push_back({pos, height});
        //NB check right 

        if(i == 0) {
            table[NEITHER][i] = 0;
            table[LEFT][i] = table[RIGHT][i] = 1;
        } else {
            //Check last right was OK
            if(vals[i-1].first + vals[i-1].second >= vals[i].first) {
                table[RIGHT][i-1] = 0;
            }

            table[NEITHER][i] = max(table[LEFT][i-1], max(table[RIGHT][i-1], table[NEITHER][i-1]));

            if(vals[i].first-vals[i].second <= vals[i-1].first) {
                table[LEFT][i] = 0;
            } else {
                table[LEFT][i] = max(table[LEFT][i-1], table[NEITHER][i-1]) + 1;
                if(vals[i].first-vals[i].second > vals[i-1].first+vals[i-1].second) {
                    table[LEFT][i] = max(table[LEFT][i], table[RIGHT][i-1]+1);
                }
            }

            table[RIGHT][i] = max(table[LEFT][i-1], max(table[RIGHT][i-1], table[NEITHER][i-1])) + 1;
        }
    }

    int ans = max(table[LEFT][t-1], max(table[RIGHT][t-1], table[NEITHER][t-1]));
    printf("%d\n", ans);

    return 0;
}
