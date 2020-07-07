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
    unordered_map<int, int> counts;
    int n;
    scanf("%d", &n);

    int next;
    for(int i = 0; i < n; i++) {
        scanf("%d", &next);
        if(counts.count(next)) counts[next]++;
        else counts.insert({next, 1});
    }

    int max;
    n % 2 == 0 ? max = n/2 : max = n/2 + 1; 
    for(auto i = counts.begin(); i != counts.end(); i++) {
        if(i->second > max) {
            printf("NO\n");
            return 0;
        }
    }

    printf("YES\n");

    return 0;
}
