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

#define BIG_NUM 100000

int main () {
    int days;
    scanf("%d", &days);

    int table[3][days+1];
    int next;
    table[0][1] = 1;
    table[1][1] = table[2][1] = BIG_NUM;

    for(int i = 1; i <= days; i++) {
        scanf("%d", &next);

        if(i == 1) {
            if(next == 3) {
                table[1][i] = 0;
                table[2][i] = 0;
            } else {
                if(next != 0) table[next][i] = 0;
            }
        } else {
            table[1][i] = table[2][i] = BIG_NUM;
            table[0][i] = min(table[0][i-1], min(table[1][i-1], table[2][i-1])) + 1;

            if (next == 1 || next == 3) {
                table[1][i] = min(table[0][i-1], min(table[2][i-1], table[1][i-1]+1)); 
            }

            if(next == 2 || next == 3) {
                table[2][i] = min(table[0][i-1], min(table[1][i-1], table[2][i-1] + 1));
            }
        }
    }

    int ans = min(table[0][days], min(table[1][days], table[2][days]));
    printf("%d\n", ans);
    return 0;
}
