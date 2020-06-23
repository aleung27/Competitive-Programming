#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    scanf("%d", &n);

    deque<int> cards;

    int next;
    for(int i = 0; i < n; i++) {
        scanf("%d", &next);
        cards.push_back(next);
    }

    int s = 0, d = 0;
    int i = 0;

    while(cards.size() > 0) {
        if(cards.front() > cards.back()) {
            i % 2 == 0 ? s += cards.front() : d += cards.front();
            cards.pop_front();
        } else {
            i %2 == 0 ? s += cards.back() : d += cards.back();
            cards.pop_back();
        }

        i++;
    }

    printf("%d %d\n", s, d);

    return 0;
}