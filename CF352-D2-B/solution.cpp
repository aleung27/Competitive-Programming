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

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int main () {
    int n;
    scanf("%d", &n);

    vector<pair<int, int>> arr;
    pair<int, int> next;

    for(int i = 0; i < n; i++) {
        scanf("%d", &next.first);
        next.second = i+1;
        arr.push_back(next);
    }

    sort(arr.begin(), arr.end(), cmp);

    vector<pair<int, int>> ans;
    for(int i = 0; i < n; i++) {
        if(i == n-1) {
            ans.push_back({arr[i].first, 0});
        } else {
            int gap = 0;
            bool incorrect = false;

            int j = i+1;
            while(arr[j].first == arr[i].first && j < n) {
                if(!gap) gap = arr[j].second-arr[i].second;
                else if(gap && arr[j].second-arr[j-1].second != gap) incorrect = true;

                j++;
            }

            if(!incorrect) ans.push_back({arr[i].first, gap});
            i = j-1;
        }
    }

    printf("%d\n", (int)ans.size());

    for(const auto& a: ans) {
        printf("%d %d\n", a.first, a.second);
    }

    return 0;
}
