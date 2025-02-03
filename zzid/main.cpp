#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("zzid.in");
ofstream fout("zzid.out");
int h, w, dif;
int x, nr = 0;
int sp[1000004];
int main()
{
    fin >> h >> w;
    for(int i = 1; i <= h; i++){
        fin >> x;
        int s = 0;
        for(int j = 1; j <= x; j++){
            int y;
            fin >> y;
            s = s + y;
            if(j < x){
                nr++;
                sp[nr] = s;
            }
        }
    }
    sort(sp+1, sp+nr+1);
    int scvmax = 0, scvmaxi;
    int secv = 1;
    for(int i = 2; i <= nr; i++){
        if(sp[i] == sp[i-1]){
            secv++;
        }else{
            secv = 1;
        }
        if(secv > scvmax){
            scvmax = secv;
            scvmaxi = sp[i];
            dif = w-2*scvmaxi;
            if(dif < 0){
                dif = -dif;
            }
        }else if(secv == scvmax){
            int d = w-2*sp[i];
            if(d < 0){
                d = -d;
            }
            if(d < dif){
                scvmaxi = sp[i];
                dif = d;
            }
        }
    }
    fout << h-scvmax << ' ' << dif;
    return 0;
}
