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
    int n;
    scanf("%d", &n);
    vector<int> ratings;

    int next;
    for(int i = 0; i < n; i++) {
        scanf("%d", &next);
        ratings.push_back(next);
    }

    int below = 0;
    for(auto& i: ratings) {
        if(i % 2 == 0) i /= 2;
        else {
            if(below > 0) {
                i < 0 ? i /= 2 : i = i/2 + 1;
                below--;
            } else {
                i < 0 ? i = i/2 - 1 : i/= 2;
                below++;
            }
        }
    }

    for(const auto& i: ratings) {
        printf("%d\n", i);
    }


    return 0;
}
