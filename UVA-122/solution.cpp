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

void traverse(unordered_map<string, int>& nodes, vector<int>& list) {
    queue<string> q;
    if(nodes.count("")) {
        q.push("");
    }

    while(!q.empty()) {
        string at = q.front();
        q.pop();
        list.push_back(nodes[at]);

        if(nodes.count(at + "L")) {
            q.push(at + "L");
        }

        if(nodes.count(at + "R")) {
            q.push(at + "R");
        }
    }
}

int main () {
    FASTIO
    string s;
    unordered_map<string, int> nodes;
    bool notComplete = false;
    int counter = 0;

    while(1) {
        cin >> s;
        if(cin.eof()) break;

        if(s == "()") {
            if(notComplete) cout << "not complete\n";
            else {
                // Parse the nodes traversing the ndoes in the map
                // Remember to error check for missing nodes!
                vector<int> list;
                traverse(nodes, list);
                if(list.size() != counter) {
                    cout << "not complete\n";
                } else {
                    for(int i = 0; i < list.size(); i++) {
                        i == list.size() - 1 ? cout << list[i] << endl : cout << list[i] << " "; 
                    }
                }
            }

            notComplete = false;
            nodes.clear();
            counter = 0;
        } else {
            string num = "", seq = "";
            bool split = false;
            for(const auto& c: s) {
                if(c == ',') split = true;
                else if(c == '(' || c == ')') continue;
                else if(!split) {
                    num += c;
                } else {
                    seq += c;
                }
            }

            if(nodes.count(seq)) {
                notComplete = true;
            } else {
                nodes.insert({seq, stoi(num)});
                counter++;
            }
        }

    }


    return 0;
}
