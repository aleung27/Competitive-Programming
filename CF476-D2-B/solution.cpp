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

int success = 0;

void process(int at, int pos, int ans, string s) {
    if(at == s.length()) {
        if(pos == ans) success++;
        return;
    }

    if(s[at] == '+') process(at+1, pos+1, ans, s);
    else if(s[at] == '-') process(at+1, pos-1, ans, s);
    else {
        process(at+1, pos+1, ans, s);
        process(at+1, pos-1, ans, s);
    }
}

int main () {
    FASTIO
    string sent, got;
    cin >> sent >> got;

    int end = 0;
    for(const auto& c: sent) {
        c == '+' ? end++ : end--;
    }

    process(0, 0, end, got);
    int possibilities = 1;
    for(const auto& c: got) {
        if(c == '?') possibilities *= 2;
    }

    printf("%.10lf\n", (double)success/(double)possibilities);


    return 0;
}
