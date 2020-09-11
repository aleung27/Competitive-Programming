#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define X real()
#define Y imag()
#define EPS 0.000000001
#define M_PI 3.14159265358979323846
#define CROSSPROD(a, b) (conj(a) * (b)).Y
#define DOTPROD(a, b) ((a).X * (b).X + (a).Y + (b).Y)
#define FASTIO ios::sync_with_stdio(false);

int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};

template <class T>
T gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

template <class T>
T lcm(T a, T b) {
    return a * b / gcd<T>(a, b);
}

template <class T>
T modpow(T x, T n, T m) {
    if (n == 0) return 1 % m;
    ll u = modpow(x, n / 2, m);
    u = (u * u) % m;
    if (n % 2 == 1) u = (u * x) % m;
    return u;
}

ll mypow(ll x, ll n, ll base_x) {
    if(n == 0) return 1;
    if(n == 1) return x;
    
    return mypow(x*base_x, n-1, base_x);
}

int main() {
    char s_coeff[1000000];
    char s_x_i[1000000];

    while(fgets(s_coeff, 1000000, stdin) != NULL) {
        vector<int> coeff;
        vector<int> x_i;
        
        fgets(s_x_i, 1000000, stdin);

        char * ptr;
        ptr = strtok(s_coeff, " \n");
        while(ptr != NULL) {
            coeff.push_back(atoi(ptr));
            ptr = strtok(NULL, " \n");
        }

        ptr = strtok(s_x_i, " \n");
        while(ptr != NULL) {
            x_i.push_back(atoi(ptr));
            ptr = strtok(NULL, " \n");
        }

        int pos = 0;
        for(const auto &x: x_i) {
            ll total = 0;
            int counter = 0;

            for(int i = coeff.size()-1; i >= 0; i--) {
                total += mypow(x, counter, x)*(ll)coeff[i];
                counter++;
            }

            pos == x_i.size() -1 ? printf("%lld\n", total): printf("%lld ", total);
            pos++;
        }

        memset(s_coeff, '\0' ,1000000);
        memset(s_x_i, '\0' ,1000000);
    }

    return 0;
}
