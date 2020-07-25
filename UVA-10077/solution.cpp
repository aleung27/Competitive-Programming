#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define X real()
#define Y imag()
#define EPS 0.000000001
#define M_PI 3.14159265358979323846
#define CROSSPROD(a, b) (conj(a) * (b)).Y
#define DOTPROD(a, b) ((a).X * (b).X + (a).Y + (b).Y)
#define FASTIO ios::sync_with_stdio(false);

int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};

template <class T>
T gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    FASTIO
    int ansM, ansN;

    while (1) {
        cin >> ansM >> ansN;
        if(ansM == ansN && ansM == 1) break;
        int currentM = 1, currentN = 1;
        int leftM = 0, leftN = 1;
        int rightM = 1, rightN = 0;
        string s = "";

        while(1) {
            if(currentN == ansN && currentM == ansM) break;
            if((double)currentM/(double)currentN < (double)ansM/(double)ansN) {
                int newM, newN;
                newM = currentM + rightM;
                newN = currentN + rightN;
                leftM = currentM;
                leftN = currentN;
                currentM = newM;
                currentN = newN;

                s += "R";
            } else {
                int newM, newN;
                newM = currentM + leftM;
                newN = currentN + leftN;
                rightM = currentM;
                rightN = currentN;
                currentM = newM;
                currentN = newN;
                
                s += "L";
            }
        }

        cout << s << endl;
    }

    return 0;
}
