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
    unordered_set<int> uniq;
    int n;
    scanf("%d", &n);
 
    int next;
    for(int i = 0; i < n; i++) {
        scanf("%d", &next);
        uniq.insert(next);
    }


    if(uniq.size() == 1 || uniq.size() == 2) {
        printf("YES\n");
    } else if(uniq.size() == 3) {
        vector<int> el;
        for(const auto& a : uniq) {
            el.push_back(a);
        }

        sort(el.begin(), el.end());
        if((el[1] - el[0] == el[2] - el[1])) printf("YES\n");
        else printf("NO\n");
    } else {
        printf("NO\n");
    }


    return 0;
}
