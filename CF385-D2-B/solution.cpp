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
    string s;
    cin >> s;

    int lastend = 0;
    int count = 0;
    while(1) {
        int start = s.find("bear", lastend);
        if(start == string::npos) break;
        int end = start+3;

        int extra = s.find("bear", end);
        if(extra != string::npos) count += (start+1)*(extra+3-end);
        else count += (start+1)*(s.length()-end);

        lastend = end;
    }

    cout << count << endl;


    return 0;
}
