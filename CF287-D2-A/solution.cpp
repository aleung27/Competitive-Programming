#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define X real()
#define Y imag()
#define EPS 0.000000001
#define M_PI 3.14159265358979323846
#define CROSSPROD(a, b) (conj(a)*b).Y

template <class T>
T gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main () {
    char grid[4][4];

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j ++) {
            scanf(" %c", &grid[i][j]);
        }
    }

    bool done = false;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(j != 3 && i != 3) {
                if(grid[i][j+1] == grid[i][j] && grid[i+1][j] == grid[i][j]) done = true;
            }

            if(j!= 0 && i != 0) {
                if(grid[i][j-1] == grid[i][j] && grid[i-1][j] == grid[i][j]) done = true;
            }

            if(i != 3 && j != 0) {
                if(grid[i+1][j] == grid[i][j] && grid[i+1][j-1] == grid[i][j]) done = true;
            }

            if(i != 3 && j != 3) {
                if(grid[i+1][j] == grid[i][j] && grid[i+1][j+1] == grid[i][j]) done = true;
            }

            if(done) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");

    return 0;
}
