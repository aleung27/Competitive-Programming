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

void process(string& ans, unordered_set<char> (&notFound), int qCount, const string& s, int i) {
    auto iter = notFound.begin();

    for(int j = 0; j < s.length(); j++) {
        if (s[j] != '?') ans += s[j];
        else {
            if(qCount > 0 && j >= i) {
                ans += *iter;
                iter++;
                qCount--;
            }
            else ans += 'A';
            
        } 
    }
}

int main () {
    FASTIO
    string s;
    string ans = "";
    unordered_map<char, int> found;
    unordered_set<char> notFound;
    int qCount = 0;

    cin >> s;
    if(s.length() < 26) {
        cout << "-1\n"; 
        return 0;
    }

    for(int i = 0; i < 26; i++) notFound.insert((char)(65+i));

    for(int i = 0; i < 26; i++) {
        if (s[i] == '?') qCount++;
        else {
            if(found.count(s[i])){
                found[s[i]]++;    
            } else found.insert({s[i],1});
            notFound.erase(s[i]);    
        }
    }

    if(found.size() + qCount == 26) {
        process(ans, notFound, qCount, s, 0);
        cout << ans << endl;
        return 0;
    }

    bool done = false;
    for(int i = 1; i <= s.length()-26; i++) {
        if (s[i-1] == '?') qCount--;
        else {
            if(found.count(s[i-1])) {
                found[s[i-1]]--;
                if(found[s[i-1]] == 0) {
                    found.erase(s[i-1]);
                    notFound.insert(s[i-1]);
                }
            }
        }

        if (s[i+25] == '?') qCount++;
        else {
            if(found.count(s[i+25])) found[s[i+25]]++;
            else {
                found.insert({s[i+25], 1});
                notFound.erase(s[i+25]);
            }
        }

        if(found.size() + qCount == 26) done = true;

        if(done) {
            process(ans, notFound, qCount, s, i);
            break;
        };
    }

    if(done) cout << ans << endl;
    else cout << "-1\n";


    return 0;
}
