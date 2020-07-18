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

bool cmp (const pair<int, char> &a, const pair<int, char> &b) {
    if(a.first == b.first) return a.second == 'S';
    return a.first < b.first;
}

int main () {
    int p, q, l ,r;
    scanf("%d %d %d %d", &p, &q, &l, &r);

    vector<pair<int, int>> timesA;
    vector<pair<int, int>> timesB;
    pair<int, int> next;

    for(int i = 0; i < p; i++) {
        scanf("%d %d", &next.first, &next.second);
        timesA.push_back(next);
    }

    for(int i = 0; i < q; i++) {
        scanf("%d %d", &next.first, &next.second);
        timesB.push_back(next);
    }

    int counter = 0;
    for(int i = l; i <= r; i++) {
        vector<pair<int, char>> intervals;
        for(const auto& a : timesA) {
            intervals.push_back({a.first, 'S'});
            intervals.push_back({a.second, 'E'});
        }


        for(const auto& b : timesB) {
            intervals.push_back({b.first + i, 'S'});
            intervals.push_back({b.second + i, 'E'});
        }

        sort(intervals.begin(), intervals.end(), cmp);
        
        for(int i = 0; i < intervals.size()-1; i++) {
            if(intervals[i].second == intervals[i+1].second) {
                counter++;
                break;
            }
        }
    }

    printf("%d\n", counter);
    return 0;
}
