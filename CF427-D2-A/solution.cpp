#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    scanf("%d", &n);

    int officers = 0;
    int crimes = 0;
    int next;
    for(int i = 0; i < n; i++) {
        scanf("%d", &next);
        if (next > 0) officers += next;
        else if (next < 0) {
            if(officers > 0) {
                officers--;
            } else {
                crimes++;
            }
        }
    }

    printf("%d\n", crimes);

    return 0;
}