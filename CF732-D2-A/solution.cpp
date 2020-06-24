#include <bits/stdc++.h>

using namespace std;

int main() {
    int price, coin;
    scanf("%d %d", &price, &coin);

    int buys = 1;

    for(int i = buys; i <= 10; buys++) {
        if((price*buys - coin) % 10 == 0 || price*buys % 10 == 0)  break;
    }

    printf("%d\n", buys);

    return 0;
}