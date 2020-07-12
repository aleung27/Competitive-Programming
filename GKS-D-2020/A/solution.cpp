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
    int t, n, c = 1;
    vector<int> visitors;
    scanf("%d", &t);

    for(; t > 0; t--) {
        scanf("%d", &n);
        visitors.clear();

        int next;
        for(int i = 0; i < n; i++) {
            scanf("%d", &next);
            visitors.push_back(next);
        }

        int largest = INT_MIN;
        int count = 0;
        for(int i = 0;i < n; i++) {
            if(i == n-1) {
                if(visitors[i] > largest) count++;
            } else {
                if(visitors[i] > largest){
                    largest = visitors[i];
                    if(visitors[i+1] < largest) {
                        count++;
                    }
                } 
            }
        }

        printf("Case #%d: %d\n", c, count);
        c++;
    }


    return 0;
}
