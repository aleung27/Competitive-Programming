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

    vector<int> heights;
    int next;
    for(int i = 0; i < n; i++) {
        scanf("%d", &next);
        heights.push_back(next);
    }

    int biggest = INT_MIN;
    for(int i = 0; i < n; i++) {
        int count = 1;
        int last = heights[i];

        for(int j = i-1; j >= 0; j--) {
            if(last >= heights[j]) {
                count++;
                last = heights[j];
            } else break;
        }

        last = heights[i];
        for(int j = i + 1; j < n; j++) {
            if(last >= heights[j]) {
                count++;
                last = heights[j];
            } else break;
        }

        count > biggest ? biggest = count : count = 0;
    }

    printf("%d\n", biggest);


    return 0;
}
