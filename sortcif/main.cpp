#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("sortcif.in");
ofstream fout("sortcif.out");
int n, x;
int f[92][104];
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> x;
        int y = x;
        int s = 0;
        do{
            s += y%10;
            y = y/10;
        }while(y > 0);
        f[s][0]++;
        f[s][f[s][0]] = x;
    }
    for(int i = 0; i <= 90; i++){
        sort(f[i]+1, f[i]+f[i][0]+1);
        for(int j = 1; j <= f[i][0]; j++){
            fout << f[i][j] << ' ';
        }
    }
    return 0;
}
