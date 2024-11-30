#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("credite.in");
ofstream fout("credite.out");
int n;
int p[10004][504];
int z[10004];
int f[10004];
long long s= 0;
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        int c, t;
        fin >> c >> t;
        z[t]++;
        p[t][z[t]] = c;
    }
    for(int i = 1; i <= 10000; i++){
        sort(p[i]+1, p[i]+z[i]+1);
    }
    int nz = 0;
    for(int i = 1; i <= 10000; i++){
        for(int j = z[i]; j >= 1; j--){
            if(nz < i){
                nz++;
                f[nz] = p[i][j];
            }else{
                int vmin = 10000;
                int vmini=0;
                for(int o = 1; o <= nz; o++){
                    if(f[o] < vmin){
                        vmin = f[o];
                        vmini = o;
                    }
                }
                if(p[i][j] > vmin){
                    f[vmini] = p[i][j];
                }
            }
        }
    }
    s = 0;
    for(int i = 1; i <= nz; i++){
        s = s+f[i];
    }
    fout << s;
    return 0;
}
