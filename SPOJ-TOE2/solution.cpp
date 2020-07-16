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

pair<int, int> check(char grid[3][3]) {
    pair<int, int> lines = {0, 0};
    for(int i = 0; i < 3; i++) {
        if(grid[i][0] == grid[i][1] && grid[i][0] == grid[i][2] && grid[i][0] != '.') {
            grid[i][0] == 'X' ? lines.first++ : lines.second++;
        }

        if(grid[0][i] == grid[1][i] && grid[0][i] == grid[2][i] && grid[0][i] != '.') {
            grid[0][i] == 'X' ? lines.first++ : lines.second++;
        }
    }

    if(grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2] && grid[0][0] != '.') {
        grid[0][0] == 'X' ? lines.first++ : lines.second++;
    }

    if(grid[0][2] == grid[1][1] && grid[2][0] == grid[0][2] && grid[0][2] != '.') {
        grid[0][2] == 'X' ? lines.first++ : lines.second++;
    }

    return lines;
}

int main () {
    for(;;) {
        char grid[3][3];
        int xCount = 0, oCount = 0;
        int dotCount = 0;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                scanf(" %c", &grid[i][j]);
                if(grid[i][j] == 'e') return 0;
                else if(grid[i][j] == 'X') xCount++;
                else if(grid[i][j] == 'O') oCount++;
                else if(grid[i][j] == '.') dotCount++;
            }
        }

        if(xCount < oCount || xCount > oCount + 1) {
            printf("invalid\n");
            continue;
        }

        pair<int, int> lines = check(grid);
        if(lines.first == 0 && lines.second == 0 && dotCount == 0) {
            printf("valid\n");
        } else if(lines.first+lines.second == lines.second || lines.first + lines.second == lines.first) {
            if(lines.first && xCount == (oCount+1)) printf("valid\n");
            else if(lines.second && xCount == oCount) printf("valid\n");
            else printf("invalid\n");
        } else {
            printf("invalid\n");
        }
    }


    return 0;
}
