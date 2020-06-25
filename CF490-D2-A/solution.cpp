#include <bits/stdc++.h>

using namespace std;

int main () {
    queue<int> program, maths, pe;
    int n;
    scanf("%d", &n);

    int next;
    for(int i = 0; i < n; i++) {
        scanf("%d", &next);
        next == 1 ? program.push(i+1) : (next == 2 ? maths.push(i+1) : pe.push(i+1));
    }

    int teams = min(program.size(), min(maths.size(), pe.size()));
    printf("%d\n", teams);

    for(int i = 0; i < teams; i++) {
        printf("%d %d %d\n", program.front(), maths.front(), pe.front());
        program.pop();
        maths.pop();
        pe.pop();
    }


    return 0;
}