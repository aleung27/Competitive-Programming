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

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
}

int main () {
    int n, containers;
    scanf("%d %d", &n, &containers);

    vector<pair<int, int>> boxes;
    pair<int, int> next;
    for(int i = 0; i < containers; i++) {
        scanf("%d %d", &next.first, &next.second);
        boxes.push_back(next);
    }

    sort(boxes.begin(), boxes.end(), cmp);

    int total = 0;
    for(auto i = boxes.begin(); i != boxes.end(); i++) {
        if(n > i->first) {
            n -= i->first;
            total += i->first*i->second;
        } else {
            total += n*i->second;
            break;
        }
    }

    printf("%d\n", total);

    return 0;
}
