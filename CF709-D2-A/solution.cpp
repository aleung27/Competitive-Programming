#include <bits/stdc++.h>

using namespace std;

int main () {
    int noranges, maxsize, limit;
    scanf("%d %d %d", &noranges, &maxsize, &limit);

    int curr = 0;
    int count = 0;

    int orange;
    for(int i = 0; i < noranges; i++) {
        scanf("%d", &orange);
        if (orange > maxsize) continue;

        curr += orange;
        if (curr > limit){
            count++;
            curr = 0;
        } 
            
    }    

    printf("%d\n", count);


    return 0;
}