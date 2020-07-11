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
    string num;
    cin >> num;

    int count = 0;
    ll result = 0;

    while(num.length() != 1) {
        result = 0;
        for(int i = 0;i < num.length(); i++) {
            result += num[i] - '0';
        }

        num = to_string(result);
        count++;
    } 

    printf("%d\n", count);



    return 0;
}
