#include <bits/stdc++.h>

using namespace std;

int main () {
    char path[55];
    char steps[55];
    int position = 0;

    scanf("%s %s", path, steps);

    int i = 0;
    while(*(steps+i)) {
        if(steps[i] == path[position]) position++;
        i++;
    }

    printf("%d\n", position+1);


    return 0;
}