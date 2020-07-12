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

int main () {
    int t;
    scanf("%d", &t);

    int n, q;
    for(int c = 1; c <= t; c++) {
        scanf("%d %d", &n, &q);
        pair<int, int> rooms[n+1];
        rooms[1].first = INT_MAX;
        rooms[n].second = INT_MAX;

        int next;
        for(int i = 1; i < n; i++) {
            scanf("%d", &next);
            rooms[i].second = next;
            rooms[i+1].first = next;
        }

        pair<int, int> query;
        int start, end;
        vector<int> ans;
        for(int i = 0; i < q; i++) {
            scanf("%d %d", &query.first, &query.second);
            start = end = query.first;

            int lastmove = start;
            for(int j = 1; j < query.second; j++) {
                if(rooms[start].first < rooms[end].second) {
                    start--;
                    lastmove = start;
                } else {
                    end++;
                    lastmove = end;
                }
            }

            ans.push_back(lastmove);
        }

        printf("Case #%d: ", c);
        for(int i = 0; i < ans.size(); i++){
            i == ans.size()- 1? printf("%d\n", ans[i]) : printf("%d ", ans[i]);
        }
    }


    return 0;
}
