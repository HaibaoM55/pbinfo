#include <fstream>
using namespace std;
ifstream fin("graf_partial.in");
ofstream fout("graf_partial.out");
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
        if(!f[min(x, y)][max(x,y)]){
            f[min(x, y)][max(x,y)] = true;
            if(x % 2 != y % 2){
                r++;
            }
        }
    }
    fout << r;
    return 0;
}
