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

struct key {
    int x, y;
    char val;
};

bool valid(key a, key b, int dist) {
    if(sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y)) <= (dist + EPS)) return true;
    return false;
}

int main () {
    int n, m, dist;
    scanf("%d %d %d", &n, &m, &dist);

    vector<key> keyboard;
    unordered_map<char, bool> capital;
    char next;
    bool isShift = false;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf(" %c", &next);
            key nextkey = {j, i, next};
            if(next == 'S') isShift = true;
            keyboard.push_back(nextkey);
            if(!capital.count(next)) capital.insert({next, false});
        }
    }

    for(int i = 0; i < keyboard.size(); i++) {
        if(keyboard[i].val == 'S'){
            for(int j = 0; j < keyboard.size(); j++) {
                if(keyboard[j].val == 'S') continue;
                else if(capital.count(keyboard[j].val) && capital[keyboard[j].val] == true) continue;
                else if(valid(keyboard[i], keyboard[j], dist)) {
                    if(capital.count(keyboard[j].val)) capital[keyboard[j].val] = true;
                    else capital.insert({keyboard[j].val, true});
                }
            }
        }
    }

    int length;
    int counter = 0;
    scanf("%d", &length);
    
    for(int i = 0; i < length; i++) {
        scanf(" %c", &next);
        if(isupper(next) && !isShift) {
            printf("-1\n");
            return 0;
        } else if(!capital.count(tolower(next))) {
            printf("-1\n");
            return 0;
        } else if(isupper(next)) {
            if(!capital[tolower(next)]) {
                counter++;
            }
        }
    }

    printf("%d\n", counter);

    return 0;
}
