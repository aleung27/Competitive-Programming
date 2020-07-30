#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define X real()
#define Y imag()
#define EPS 0.000000001
#define M_PI 3.14159265358979323846
#define CROSSPROD(a, b) (conj(a)*(b)).Y
#define DOTPROD(a, b) ((a).X*(b).X + (a).Y+(b).Y)
#define FASTIO ios::sync_with_stdio(false);

int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};

template <class T>
T gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

template <class T>
T modpow(T x, T n, T m) {
    if(n == 0) return 1 % m;
    ll u = modpow(x, n/2, m);
    u = (u*u)%m;
    if(n%2 == 1) u = (u*x)%m;
    return u;
}

string find(string s, unordered_map<string, string>& links) {
    while(links[s] != s) s = links[s];
    return s;
}

int join(string s1, string s2, unordered_map<string, string>& links, unordered_map<string, int>& size) {
    s1 = find(s1, links);
    s2 = find(s2, links);

    if(size[s1] < size[s2]) swap(s1, s2);
    size[s1] += size[s2];
    links[s2] = s1; 
    return size[s1];
}

int main () {
    FASTIO
    int t, m;
    cin >> t;

    while(t--) {
        cin >> m;
        string s1, s2;
        unordered_map<string, int> size;
        unordered_map<string, string> links;

        for(int i = 0; i < m; i++) {
            cin >> s1 >> s2;

            if(!links.count(s1)) {
                size.insert({s1, 1});
                links.insert({s1, s1});
            }
            if(!links.count(s2)) {
                size.insert({s2, 1});
                links.insert({s2, s2});
            }

            if(find(s1, links) != find(s2, links)) {
                cout << join(s1, s2, links, size) << endl;
            } else {
                cout << size[find(s1, links)] << endl;
            }
        }
    } 


    return 0;
}
