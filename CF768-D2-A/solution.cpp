#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    map<int, int> ppl;

    scanf("%d", &n);

    int min = INT_MAX;
    int max = INT_MIN;

    int next;
    for(int i = 0; i < n; i++) {
        scanf("%d", &next);
        if(next < min) min = next;
        if(next > max) max = next;
        if(ppl.count(next)) {
            ppl[next]++;
        } else ppl.insert(make_pair(next, 1));
    }

    min != max ? printf("%d\n", n-ppl[min]-ppl[max]): printf("%d\n", n-ppl[min]);

    return 0;
}