#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
using namespace std;

struct mytriple {
    int first;
    int second;
    int index;
};

bool mycompare(struct mytriple t1, struct mytriple t2){
    return t1.first < t2.first;
}

int main() {
    int tests;
    int events;
    int start, end;
    bool C[24*60+5];
    bool J[24*60+5];
    char output[1005];
    bool fail;
    scanf("%d", &tests);

    for(int a = 0; a < tests; a++) {
        scanf("%d", &events);
        struct mytriple activities[events];
        fail = false;
        memset(C, false, sizeof(bool)*(24*60+5));
        memset(J, false, sizeof(bool)*(24*60+5));
        memset(output, '0', sizeof(char)*1005);

        for(int i = 0; i < events; i++){
            struct mytriple temp;
            scanf("%d %d", &temp.first, &temp.second);
            temp.index = i;
            activities[i] = temp;
        }

        sort(activities, activities + events, mycompare);

        for(int i = 0; i < events; i++){
            start = activities[i].first;
            end = activities[i].second;

            if(C[start] || C[end-1]){
                //C is busy
                if(J[start] || J[end-1]){
                    fail = true;
                    break;
                } else {
                    for(int j = start; j < end; j++){
                        J[j] = true;
                    }
                    output[activities[i].index] = 'J';
                } 
            } else {
                for(int j = start; j < end; j++){
                    C[j] = true;
                }
                output[activities[i].index] = 'C';
            }
        }

        if(fail){
            printf("Case #%d: IMPOSSIBLE\n", a+1);
        } else {
            output[events] = '\0';
            printf("Case #%d: %s\n", a+1, output);  
        }
    }

    return 0;
}