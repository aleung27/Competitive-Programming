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
    int n;
    string s;
    cin >> n >> s;

    vector<char> front, back;
    bool b = true;

    for(int i = n-1; i >= 0; i--) {
        b ? back.push_back(s[i]) : front.push_back(s[i]);
        b = !b;
    } 

    reverse(back.begin(), back.end());

    for(const auto& c: front) cout << c;
    for(const auto& c: back) cout << c;

    cout << endl;

    return 0;
}
