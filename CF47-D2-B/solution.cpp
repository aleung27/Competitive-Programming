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

int main () {
    FASTIO
    int vals[3] = {1, 2, 3};
    int ABC[100];
    string equalities[3];

    for(int i = 0; i < 3; i++) {
        cin >> equalities[i];
    }

    bool done = false;
    do {
        // A, B, C
        ABC[65] = vals[0];
        ABC[66] = vals[1];
        ABC[67] = vals[2];

        bool correct= true;
        for(int i =0;i < 3; i++) {
            if(equalities[i][1] == '>') {
                if(ABC[equalities[i][0]] > ABC[equalities[i][2]]) correct = false;
            } else {
                if(ABC[equalities[i][0]] < ABC[equalities[i][2]]) correct= false;
            }
        }

        if(correct) {
            done = true;
            break;
        };
    } while(next_permutation(vals, vals + 3));

    if(!done) cout << "Impossible\n";
    else {
        char ans[3];
        ans[3-ABC[65]] = (char)65;
        ans[3-ABC[66]] = (char)66;
        ans[3-ABC[67]] = (char)67;

        cout << ans[0] << ans[1] << ans[2] << endl;
    }


    return 0;
}
