#include <fstream>
using namespace std;
ifstream fin("prodmax.in");
ofstream fout("prodmax.out");
int n, m;
int a[104][104];
int vmax=0;
int x[1004];
int z=0;
int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            fin >> a[i][j];
        }
    }
    for(int j = 1; j <= m; j++){
        int nr = 0;
        for(int i = 1; i <= n; i++){
            if(a[i][j] == 0){
                nr = 0;
                break;
            }else if(a[i][j]==2){
                nr++;
            }
        }
        if(nr > vmax){
            vmax = nr;
            z=1;
            x[1] = j;
        }else if(nr == vmax){
            z++;
            x[z] = j;
        }
    }
    for(int i = 1; i <= z; i++){
        fout << x[i] << ' ';
    }
    return 0;
}
