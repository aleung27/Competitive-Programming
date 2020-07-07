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

ll val(ll at, ll k) {
    return (ll)(((double)(k-at+1)/(double)2)*(at+k) + EPS);
}

// Greatest sum <= n
ll query(ll n, ll k) {
    ll left = 1;
    ll right = k;

    while(left <= right) {
        ll mid = (left+right)/2;

        if(val(mid, k) == n) return mid;
        else if(val(mid, k) < n) right = mid-1;
        else if(val(mid, k) > n) left = mid + 1;
    }

    if(right <= 0) return -1; 
    else return max(left, right);
}

int main () {
    FASTIO
    ll n, k;
    cin >> n >> k;

    n--;
    k--;

    ll index = query(n, k);
    if(index == -1) cout << "-1\n";
    else {
        if(val(index, k) == n) cout << k-index+1 << endl;
        else cout << k-index+2 <<endl;
    }


    return 0;
}
