#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
ifstream fin("listavecini.in");
ofstream fout("listavecini.out");
int n, x, y;
bool v[104][104];
int m[104];
int main(){
    fin >> n;
    while(fin >> x >> y){
        if(!v[x][y]){
            m[x]++;
            v[x][y] = true;
        }
        if(!v[y][x]){
            m[y]++;
            v[y][x] = true;
        }
    }
    for(int i = 1; i <= n; i++){
        fout << m[i] << ' ';
        for(int j = 1; j <= n; j++){
            if(v[i][j]){
                fout << j << ' ';
            }
        }
        fout << '\n';
    }
    return 0;
}
