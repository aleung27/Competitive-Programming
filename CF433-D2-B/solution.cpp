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

    vector<int> stones;
    vector<int> cheap;
    int next;
    for(int i = 0; i < n; i++) {
        scanf("%d", &next);
        stones.push_back(next);
        cheap.push_back(next);
    }

    sort(cheap.begin(), cheap.end());

    vector<ll> values;
    vector<ll> valuesCheap;

    for(int i = 0; i < n; i++) {
        if(i == 0) {
            values.push_back(stones[i]);
            valuesCheap.push_back(cheap[i]);
        } else {
            values.push_back(values[i-1]+stones[i]);
            valuesCheap.push_back(valuesCheap[i-1]+cheap[i]);
        }
    }

    int q, type, l, r;
    scanf("%d", &q);
    for(int i = 0; i < q; i++) {
        scanf("%d %d %d", &type, &l, &r);
        l--;
        r--;

        ll ans;
        if(type == 1) {
            l == 0 ? ans = values[r] : ans = values[r]-values[l-1];
        } else {
            l == 0 ? ans = valuesCheap[r] : ans = valuesCheap[r]-valuesCheap[l-1];
        }

        printf("%lld\n", ans);

    }



    return 0;
}
