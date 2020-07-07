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
    int time = INT_MAX;
    int n;
    string s;
    cin >> n;
    cin >> s;
    int particles[n];

    for(int i = 0; i < n; i++) {
        cin >> particles[i];
    }

    for(int i = 0; i < n-1; i++) {
        if(s[i] ==  'R' && s[i+1] == 'L') {
            time = min(time, (particles[i+1]-particles[i])/2);
        }
    }

    time == INT_MAX ? cout << "-1\n" : cout << time << endl;


    return 0;
}
