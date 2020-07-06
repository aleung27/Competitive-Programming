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
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;

    string s;
    int counter = 0;
    for(int i = 0; i < n; i++) {
        unordered_set <int> count;
        cin >> s;

        for(int j = 0; j < s.length(); j++) {
            if(s[j] - '0' > k) continue; 

            count.insert(s[j] - '0');
        }

        if(count.size() == k+1) counter++;
    }

    cout << counter << endl;

    return 0;
}
