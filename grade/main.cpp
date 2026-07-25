#include <fstream>
using namespace std;
ifstream fin("grade.in");
ofstream fout("grade.out");
int n, x, y;
int f[104];
bool b[104][104];
int main(){
    fin >> n;
    while(fin >> x >> y){
        if(!b[min(x, y)][max(x, y)]){
            b[min(x, y)][max(x, y)] = true;
            f[x]++;
            f[y]++;
        }
    }
    for(int i = 1; i <= n; i++){
        fout << f[i] << ' ';
    }
    return 0;
}
