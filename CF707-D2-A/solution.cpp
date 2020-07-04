#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main () {
    int r, c;
    scanf("%d %d", &r, &c);

    bool colour = false;
    char next;

    for(int i = 0; i < c; i++) {
        for(int j = 0; j < r; j++) {
            cin >> next;
            if(next == 'C' || next == 'M' || next == 'Y') colour = true;
        }
    }

    colour ? printf("#Color\n") : printf("#Black&White\n");

    return 0;
}
