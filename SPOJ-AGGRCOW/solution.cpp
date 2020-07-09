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

bool valid(int at, vector<int> stalls, int n, int c) {
    int cows = 0;
    int laststall= -1e9;
    for(int i = 0; i < n; i++) {
        if(stalls[i]-laststall >= at) {
            cows++;
            laststall = stalls[i];
        }
    }

    if(cows >= c) return true;
    return false;
} 

int main () {
    int t, n, c;
    scanf("%d", &t);

    for(; t > 0; t--) {
        scanf("%d %d", &n, &c);
        vector<int> stalls;
        int next;

        for(int i = 0; i < n; i++) {
            scanf("%d", &next);
            stalls.push_back(next);    
        }

        sort(stalls.begin(), stalls.end());

        int left = 0, right = 1e9; 

        while(left <= right) {
            int mid = (left+right)/2;
            if(!valid(mid, stalls, n, c)) right = mid-1;
            else left = mid+1; 
        }

        printf("%d\n", min(left, right));
    }
    


    return 0;
}
