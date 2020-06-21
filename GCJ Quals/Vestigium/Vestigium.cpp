#include <cstdio>
#include <utility>
#include <map>
using namespace std;

int main() {
    int tests;
    int size;
    scanf("%d", &tests);

    for (int a = 0; a < tests; a++){
        scanf("%d", &size);
        int grid[size][size];
        map <int, bool> seen; 
        int rows = 0;
        int columns = 0;
        int trace = 0;

        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                scanf("%d", &grid[i][j]);
            }
        }

        for(int i = 0; i < size; i++) {
            trace += grid[i][i];
        }


        for(int i = 0; i < size; i++) {
            seen.clear();
            for(int j = 0; j < size; j++){
                if(seen.count(grid[i][j])){
                    rows++;
                    break;
                } else {
                    seen.insert(pair<int, bool>(grid[i][j], true));
                }
            }
        }

        for(int j = 0; j < size; j++) {
            seen.clear();
            for(int i = 0; i < size; i++){
                if(seen.count(grid[i][j])){
                    columns++;
                    break;
                } else {
                    seen.insert(pair<int, bool>(grid[i][j], true));
                }
            }
        }

        printf("Case #%d: %d %d %d\n", a+1, trace, rows, columns);
    }

    return 0;
}