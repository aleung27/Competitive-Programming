#include <bits/stdc++.h>

using namespace std;

int main () {
    int a, b;
    scanf("%d %d", &a, &b);

    int biggest = max(a, b);
    int count = 0;

    for(int i = 6; i > 0; i--) {
        if(i >= biggest) count++;
    }


    if(count == 6) printf("1/1\n");
    else if(count == 3) printf("1/2\n");
    else if(count == 0) printf("0/1\n");
    else if(count == 2 || count == 4) printf("%d/3\n", count/2);
    else printf("%d/6\n", count);

    return 0;
}