#include <fstream>
using namespace std;
ifstream fin("subgraf.in");
ofstream fout("subgraf.out");
int n,x,y;
bool f[104][104];
int r = 0;
bool esteprim(int x){
    if(x < 2){
        return false;
    }
    for(int i = 2; i*i <= x; i++){
        if(x % i == 0){
            return false;
        }
    }
    return true;
}
int main(){
    fin >> n;
    while(fin >> x >> y){
        if(!f[x][y]){
            f[x][y] = true;
            if(!esteprim(x) && !esteprim(y)){
                r++;
            }
        }
    }
    fout << r;
    return 0;
}
