#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    int days[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    while(1) {
        scanf("%d", &n);
        if (n == 0) break;

        int old_d, old_m, old_y, old_c;
        int d, m, y, c;
        scanf("%d %d %d %d", &old_d, &old_m, &old_y, &old_c);

        int total_days = 0, total_c = 0;

        for(int i = 1; i < n; i++) {
            scanf("%d %d %d %d", &d, &m, &y, &c);

            // Leap year
            if(y % 4 == 0 && (y % 400 == 0 || y % 100 !=  0)) {
                days[2] = 29;
            }
            
            if(old_d != days[old_m] && d == old_d+1 && m == old_m && y == old_y) {
                //One day ahead, not end of month
                total_days++;
                total_c += c - old_c;
            } else if (old_d == days[old_m] && d == 1 && m == old_m + 1 && y == old_y) {
                //Last day of month, not end of year
                total_days++;
                total_c += c - old_c;
            } else if (old_d == days[old_m] && m == 1 && old_m == 12 && d == 1 && y == old_y + 1) {
                //Last day of year
                total_days++;
                total_c += c - old_c;
            }

            days[2] = 28;
            old_d = d;
            old_m = m;
            old_y = y;
            old_c = c;
        }

        printf("%d %d\n", total_days, total_c);
    }

    return 0;
}