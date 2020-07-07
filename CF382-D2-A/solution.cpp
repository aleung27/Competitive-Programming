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
    string s, extra;
    cin >> s >> extra;    

    int index;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '|') {
            index = i;
            break;
        }
    }

    if(s.length() % 2 == 0 && extra.length() % 2 == 0) {
        cout << "Impossible\n";
        return 0;
    } else if(s.length() % 2 == 1 && extra.length() % 2 == 1) {
        cout << "Impossible\n";
        return 0;
    }

    int left = index;
    int right = s.length()-1-index;
    int extraw = extra.length();
    
    int righttoadd = 0, lefttoadd = 0; 
    if(left > right) {
        righttoadd = left-right;
        extraw -= righttoadd;
    } else if (right > left) {
        lefttoadd = right-left;
        extraw -= lefttoadd;
    }

    if(extraw < 0) {
        cout << "Impossible\n";
        return 0;
    }

    lefttoadd += extraw/2;
    righttoadd += extraw/2;

    for(int i = 0; i < index; i++) {
        cout << s[i];
    }
    for(int i = 0; i < lefttoadd; i++) {
        cout << extra[i];
    }
    cout << '|';

    for(int i = index+1; i < s.length(); i++) {
        cout << s[i];
    }
    for(int i = lefttoadd; i < lefttoadd+righttoadd; i++) {
        cout << extra[i];
    }
    cout << endl;

    return 0;
}
