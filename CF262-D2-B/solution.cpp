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
    int n, k;
    scanf("%d %d", &n, &k);

    vector<int> nums; 
    int sum = 0;

    
    int next;
    for(int i = 0; i < n; i++) {
        scanf("%d", &next);
        nums.push_back(next);
        sum += next;
    }

    for(int i = 0; i < n; i++) {
        if(nums[i] < 0 && k > 0) {
            nums[i] = -1*nums[i];
            sum += 2*nums[i];
            k--;
        } else break;
    }

    if(k != 0 && k % 2 == 1) {
        int minim = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(nums[i] < minim) minim = nums[i];
        }

        sum += -2*minim;
    }


    printf("%d\n", sum);


    return 0;
}
