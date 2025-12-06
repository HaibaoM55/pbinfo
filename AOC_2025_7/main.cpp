/*PART 1:
#include <fstream>
using namespace std;
ifstream fin("a.in");
ofstream fout("a.out");
char x[150][150];

int main(){
    for(int i = 1; i <= 142; i++){
        fin.get(x[i], 150);
        fin.get();
    }
    int nr = 0;
    for(int i = 1; i <= 142; i++){
        for(int j = 0; j < 142; j++){
            if(x[i][j] == 'S'){
                x[i+1][j] = '|';
            }else if(x[i][j] == '|'){
                if(x[i+1][j] == '^'){
                    x[i+1][j-1] = '|';
                    x[i+1][j+1] = '|';
                    nr++;
                }else{
                    x[i+1][j] = '|';
                }
            }
        }
    }
    for(int i = 1; i <= 142; i++){
        fout << x[i] << '\n';
    }
    fout << nr;
    return 0;
}
*/
#include <fstream>
#include <map>
using namespace std;
ifstream fin("a.in");
ofstream fout("a.out");
const int LINES = 142;
char grid[150][150];
map<pair<int,int>, long long> memo;
long long countTimelines(int row, int col) {
    if(row > LINES || col < 0 || col >= LINES) {
        return 1;
    }
    pair<int,int> pos = {row, col};
    if(memo.count(pos)) {
        return memo[pos];
    }
    long long result;
    if(grid[row][col] == '^') {
        result = countTimelines(row + 1, col - 1) + countTimelines(row + 1, col + 1);
    }else{
        result = countTimelines(row + 1, col);
    }
    memo[pos] = result;
    return result;
}
int main(){
    for(int i = 1; i <= LINES; i++){
        fin.get(grid[i], 150);
        fin.get();
    }
    int startCol = -1;
    for(int j = 0; j < LINES; j++){
        if(grid[1][j] == 'S'){
            startCol = j;
            break;
        }
    }
    long long nr = countTimelines(2, startCol);
    fout << nr;
    return 0;
}
