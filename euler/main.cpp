#include <fstream>
#include <vector>
using namespace std;
ifstream fin("euler.in");
ofstream fout("euler.out");
int n, x, y;
bool b[204][204];
int nr = 0;
vector<int> rasp;
void visit(int k){
    for(int i = 1; i <= n; i++){
        if(b[k][i]){
            b[k][i] = false;
            b[i][k] = false;
            visit(i);
        }
    }
    rasp.push_back(k);
}
int main(){
    fin >> n;
    while(fin >> x >> y){
        b[x][y] = true;
        b[y][x] = true;
        nr++;
    }
    visit(1);
    fout << nr+1 << '\n';
    for(int r: rasp){
        fout << r << ' ';
    }
    return 0;
}
