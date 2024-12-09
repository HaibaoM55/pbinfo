#include <fstream>
using namespace std;
ifstream fin("furnica.in");
ofstream fout("furnica.out");
int n, k;
int f[104][104];
int a[104][104];
int x;
int dl[9] = {0, -1, -1, 0, 1, 1,  1,  0, -1};
int dc[9] = {0,  0,  1, 1, 1, 0, -1, -1, -1};
int nr = 2;
int main()
{
    fin >> n >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            a[i][j] = (i+j)%6;
        }
    }
    int i1 = 1;
    int j1 = 1;
    f[1][1]=1;
    a[1][1]=0;
    int vmax = 1, vmaxi=1;
    for(int i = 1; i <= k; i++){
        fin >> x;
        i1 = i1+dl[x];
        j1 = j1+dc[x];
        nr = nr+a[i1][j1];
        a[i1][j1] = 0;
        f[i1][j1]++;
        if(f[i1][j1] > vmax){
            vmax = f[i1][j1];
            vmaxi= 1;
        }else if(f[i1][j1] == vmax){
            vmaxi++;
        }
    }
    fout << nr << ' ' << vmaxi;
    return 0;
}
