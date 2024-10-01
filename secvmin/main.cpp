#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("secvmin.in");
ofstream fout("secvmin.out");
int n, k;
int v[1000004];
int vmin[7] = {0,1000000000,1000000000,1000000000,1000000000,1000000000};
int f[7][100004];
int z[7];
int main()
{
    fin >> n >> k;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
        for(int j = 1; j <= k; j++){
            if(v[i] < vmin[j]){
                for(int p = k; p >= j+1; p--){
                    vmin[p] = vmin[p-1];
                    z[p] = z[p-1];
                    for(int pm = 1; pm <= z[p]; pm++){
                        f[p][pm] = f[p-1][pm];
                    }
                }
                vmin[j] = v[i];
                z[j] = 1;
                f[j][1] = i;
                break;
            }else if(v[i] == vmin[j]){
                z[j]++;
                f[j][z[j]] = i;
                break;
            }
        }
    }
    long long nr = 0;
    for(int i = 1; i <= n; i++){
        int vmax = 0;
        for(int j = 1; j <= k; j++){
            int p1 = 1;
            int p2 = z[j];
            while(p1 <= p2){
                int mij = (p1+p2)/2;
                if(f[j][mij] <= i){
                    p1 = mij+1;
                }else{
                    p2 = mij-1;
                }
            }
            if(f[j][z[j]] < i){
                vmax = n+1;
                break;
            }else if(f[j][z[j]] == i){
                p1 = z[j];
            }else{
                if(f[j][p1-1] >= i && p1 != 1){
                    p1--;
                }
            }
            if(f[j][p1] > vmax){
                vmax = f[j][p1];
            }
        }
        nr = nr+n-vmax+1;
    }
    fout << nr;
    return 0;
}
