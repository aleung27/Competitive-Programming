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
    FASTIO;
    int n;
    cin >> n;

    string a, b;
    for(; n >0; n--) {
        cin >> a >> b;
        if(b.length() > a.length()) {
            string temp = b;
            b.swap(a);
            a.swap(temp);
        }
        
        string res = "";
        int extra = 0;
        for(int i = 0; i < a.length(); i++) {
            if(i >= b.length()) {
                int dig = a[i] -'0' + extra;
                res += (dig%10)+48;
                extra = dig/10;
            } else {
                int dig = a[i] - '0' + b[i] - '0' + extra;
                res += (dig%10)+48;
                extra = dig/10;
            }
        }

        if(extra > 0) res += extra+48;
        
        bool zero = true;
        for(int i = 0; i < res.length(); i++) {
            if(res[i] == '0' && zero) continue;
            else {
                zero = false;
                cout << res[i];
            }
        }
        cout << endl;
    }


    return 0;
}
