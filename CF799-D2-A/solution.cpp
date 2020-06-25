#include <bits/stdc++.h>

using namespace std;

int main () {
    int ncakes, time, batch, newoventime;
    scanf("%d %d %d %d", &ncakes, &time, &batch, &newoventime);

    int totaltime = time+newoventime;
    totaltime = totaltime/time;
    int totalcakes = totaltime*batch;

    totalcakes < ncakes ? printf("YES\n") : printf("NO\n");

    return 0;
}