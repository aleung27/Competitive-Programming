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

void findAncestor(unordered_set<int>& anc, vector<int> adjlist[], int jump, int at) {
    anc.insert(at);
    
    for(int i = 0; i < jump; i++) {
        if(adjlist[at].size() == 0) return;
        at = adjlist[at][0];
    } 

    findAncestor(anc, adjlist, jump, at);
}

int main () {
    int t;
    scanf("%d", &t);

    for(int c = 1; c <= t; c++) {
        int n, a, b;
        scanf("%d %d %d", &n, &a, &b);

        vector<int> adjlist[n+1];
        unordered_set<int> ancA[n+1], ancB[n+1];
        int next;

        ancA[1].insert(1);
        ancB[1].insert(1);
        for(int i = 1; i < n; i++) {
            scanf("%d", &next);
            adjlist[i+1].push_back(next);
            findAncestor(ancA[i+1], adjlist, a, i+1);
            findAncestor(ancB[i+1], adjlist, b, i+1);
        }

        double result = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                unordered_set<int> unionNodes;
                for(const auto& val: ancA[i]) unionNodes.insert(val);
                for(const auto& val: ancB[j]) unionNodes.insert(val);
                result += unionNodes.size();

                //printf("a: %d b: %d a.size: %d b.size: %d union: %d\n", i, j, (int)ancA[i].size(), (int)ancB[j].size(), (int)unionNodes.size());
            }
        }

        printf("Case #%d: %lf\n", c, result/(n*n));
    }


    return 0;
}
