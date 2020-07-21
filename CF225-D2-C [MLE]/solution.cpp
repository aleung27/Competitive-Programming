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
     
    #define HASH 0
    #define DOT 1
     
    int main () {
        int n, m, lower, upper;
        scanf("%d %d %d %d", &n, &m, &lower, &upper);
     
        char grid[n][m];
     
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                scanf(" %c", &grid[i][j]);
            }
        }
     
        int colsHash[m];
     
        for(int i = 0; i < m; i++) {
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(grid[j][i] == '#') count++;
            }
            colsHash[i] = count;
        }
     
        // first = changes needed, second = amount in a row
        vector<pair<int, int>> table[2][m];
        table[HASH][0].push_back({colsHash[0], 1});
        table[DOT][0].push_back({n-colsHash[0], 1});
     
        for(int i = 1; i < m; i++) {
            int hashMin = INT_MAX;
            int dotMin = INT_MAX;
     
            for(int j = 0; j < table[HASH][i-1].size(); j++) {
                if(table[HASH][i-1][j].second < upper){
                    table[HASH][i].push_back({table[HASH][i-1][j].first + colsHash[i], table[HASH][i-1][j].second+1});
                }
     
                if(table[HASH][i-1][j].second >= lower) {
                    table[DOT][i].push_back({table[HASH][i-1][j].first + n - colsHash[i], 1});
                }
            }
     
            for(int j = 0; j < table[DOT][i-1].size(); j++) {
                if(table[DOT][i-1][j].second < upper) {
                    table[DOT][i].push_back({table[DOT][i-1][j].first + n - colsHash[i], table[DOT][i-1][j].second+1});
                }
     
                if(table[DOT][i-1][j].second >= lower) {
                    table[HASH][i].push_back({table[DOT][i-1][j].first + colsHash[i], 1});
                }
            }
     
            if(i >= 2) {
                table[HASH][i-2].clear();
                table[DOT][i-2].clear();
                table[HASH][i-2].shrink_to_fit();
                table[HASH][i-2].shrink_to_fit();
            }
        }
     
        int ans = INT_MAX;
        for(int i = 0; i < table[HASH][m-1].size(); i++) {
            if(table[HASH][m-1][i].second >= lower && table[HASH][m-1][i].second <= upper && table[HASH][m-1][i].first < ans) ans = table[HASH][m-1][i].first;
        }
     
        for(int i = 0; i < table[DOT][m-1].size(); i++) {
            if(table[DOT][m-1][i].second >= lower && table[DOT][m-1][i].second <= upper && table[DOT][m-1][i].first < ans) ans = table[DOT][m-1][i].first;
        }
     
        printf("%d\n", ans);
     
        return 0;
    }

