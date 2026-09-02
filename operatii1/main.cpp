#include <fstream>
using namespace std;
#define int long long
ifstream fin("operatii.in");
ofstream fout("operatii.out");
int n, x, y;
int f[400004], f2[400004];
int f1[400004];
int vmax = 0, vmaxs = 0;
signed main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> x >> y;
        y++;
        if(x == 1){
            f2[f[y]] -= y;
            f1[f[y]]--;
            f[y]++;
            if(f[y] > vmax){
                vmax = f[y];
            }
            f2[f[y]] += y;
            f1[f[y]]++;
            fout << f2[vmax]-f1[vmax] << '\n';
        }else{
            f2[f[y]] -= y;
            f1[f[y]]--;
            f[y]--;
            f2[f[y]] += y;
            f1[f[y]]++;
            if(f2[vmax] == 0 && f[0] != vmax){
                vmax--;
            }
            fout << f2[vmax]-f1[vmax] << '\n';
            f2[f[y]] -= y;
            f1[f[y]]--;
            f[y]++;
            f2[f[y]] += y;
            f1[f[y]]++;
            if(f2[vmax+1] != 0){
                vmax++;
            }
        }
    }
    return 0;
}
