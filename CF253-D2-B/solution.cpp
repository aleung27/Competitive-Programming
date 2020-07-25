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
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);

    vector<int> measurements;
    int next;
    int vals[5001] = {0};

    for(int i = 0; i < n; i++) {
        scanf("%d", &next);
        measurements.push_back(next);
        vals[next]++;
    }

    sort(measurements.begin(), measurements.end());

    int max = INT_MIN;
    for(int i = 1; i <= 2500; i++) {
        int amt = 0;

        for(int j = i; j <= 2*i; j++) {
            amt += vals[j];    
        }

        if(amt > max) max = amt;
    }

    printf("%d\n", n-max); 

    return 0;
}
