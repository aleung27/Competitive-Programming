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
    ios::sync_with_stdio(false);
    int pair[10];
    pair[5] = 52;
    pair[6] = 51;
    pair[7] = 50;
    pair[8] = 49;
    pair[9] = 48;

    string s;
    cin >> s;

    for(int i = 0; i < s.length(); i++) {
        if(s[i] - '0' > 4) {
            if(i == 0 && s[i] - '0' == 9) {
                
            } else s[i] = pair[s[i] - '0'];
        }

        cout << s[i];
    }

    cout << endl;

    return 0;
}
