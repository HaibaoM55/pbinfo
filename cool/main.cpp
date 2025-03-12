#include <fstream>
using namespace std;
ifstream fin("cool.in");
ofstream fout("cool.out");
int n, nr=0,k, c;
int v[5004];
int f[1004];
int main()
{
    fin >> c;
    fin >> n >> k;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    if(c == 1){
        int vmin= v[1];
        for(int i = 1; i <= k; i++){
            f[v[i]]++;
            vmin = min(vmin, v[i]);
        }
        bool ok = true;
        for(int i = vmin; i <= vmin+k-1; i++){
            if(f[i] != 1){
                ok=false;
                break;
            }
        }
        if(ok){
            fout << vmin+k-1;
        }else{
            int nr = 0;
            for(int i = 1; i <= k; i++){
                if(f[v[i]]== 1){
                    nr++;
                }
            }
            fout << nr;
        }
    }else{
        int vmaxa = 0,vmaxap=1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= 1000; j++){
                f[j] = 0;
            }
            int vmin = v[i], vmax = v[i];
            for(int j = i; j<=n; j++){
                f[v[j]]++;
                if(f[v[j]] > 1){
                    break;
                }
                vmin = min(vmin, v[j]);
                vmax = max(vmax, v[j]);
                if(vmin+j-i == vmax){
                    if(j-i+1 > vmaxa){
                        vmaxa = j-i+1;
                        vmaxap = 1;
                    }else if(vmaxa == j-i+1){
                        vmaxap++;
                    }
                }
            }
        }
        fout << vmaxa << '\n'<<vmaxap;
    }
    return 0;
}
