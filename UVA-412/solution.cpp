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

    while(1) {
        scanf("%d", &n);
        if(n==0) break;

        vector<int> nums;
        int next;
        for(int i = 0; i <n; i++) {
            scanf("%d", &next);
            nums.push_back(next);
        }

        int count = 0;
        int combos = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(gcd<int>(nums[i], nums[j]) == 1) count++;
                combos++;
            }
        }

        if(count == 0) printf("No estimate for this data set.\n");
        else {
            double pi = sqrt((double)(6*combos)/(double)(count));
            printf("%lf\n", pi);
        }
    }


    return 0;
}
