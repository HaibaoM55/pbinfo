#include <fstream>
#include <unordered_map>
#define int long long
using namespace std;
ifstream fin("magazin.in");
ofstream fout("magazin.out");
int c, n;
long long s;
int v[1000005];
signed main(){
    fin >> c >> n >> s;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    if(c == 1){
        long long nr = 0;
        int p1 = n;
        for(int i = 1; i <= n; i++){
            while(v[p1]+v[i] > s){
                p1--;
            }
            int p2 = p1;
            while(v[p2]+v[i] == s && p2 < i){
                nr++;
                p2--;
            }
        }
        if(nr == 0){
            fout << -1;
        }else{
            fout << nr;
        }
    }else{
        int j =1;
        long long sma = 0;
        int vmin = n+1, vmini=-1, vminj=-1;
        for(int i = 1; i <= n; i++){
            while(j <= n && sma+v[j] <= s){
                sma += v[j];
                j++;
            }
            if(sma == s){
                if(vmin > j-i){
                    vmin = j-i;
                    vmini = i;
                    vminj = j-1;
                }
            }
            sma -= v[i];
        }
        if(vmini == -1){
            fout << -1;
            return 0;
        }
        fout << vmini << ' ' << vminj;
    }
    return 0;
}
