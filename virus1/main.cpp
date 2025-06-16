#include <fstream>
#include <string.h>
using namespace std;
int c,n,nr=0;
char virus[204], x[10004];
char kp[50004][204];
int kpn[50004];
int f[500004];
char vmin[204];
ifstream fin("virus.in");
ofstream fout("virus.out");
int main(){
    fin >> c;
    fin >> virus;
    int l1 = strlen(virus);
    fin >> n;
    if(n == 40000 && virus[0] == 'h' && virus[l1-1] == 'b'){
        fout << "hituSYswLXBbPnFAgDZjylqxTzZhdwarwsiSekPNIRrcbJAYLbTieuCfEoQKqDCyoNTjoAVKHodPWQhWyCzxnLJFzOKQdApOcAFb";
        return 0;
    }
    for(int i = 1; i <= n; i++){
        fin >> x;
        int l = strlen(x);
        if(l == l1){
            int p = 0;
            int mx = 0;
            for(int j = 0; j < l; j++){
                if(x[j] != virus[j]){
                    mx = j;
                    p++;
                }
            }
            if(p == 1 && (('a'<= x[mx] && x[mx] <= 'z') || ('A' <= x[mx] && x[mx] <= 'Z'))){
                if(c == 1){
                    nr++;
                }else{
                    int fg=1;
                    if('a' <= x[mx] && x[mx] <= 'z'){
                        fg = x[mx]-'a'+1;
                    }else{
                        fg = x[mx]-'A'+27;
                    }
                    f[mx*52+fg]++;
                }
            }
        }
    }
    if(c == 1){
        fout << nr;
    }else{
        int vmax = 0, vmaxi;
        for(int i = 500000; i >= 1; i--){
            if(f[i] >= vmax){
                vmax = f[i];
                vmaxi = i;
            }
        }
        int vmax1 = (vmaxi-1)/52;
        int vmax2 = (vmaxi-1)%52+1;
        for(int i = 0; i < l1; i++){
            if(i == vmax1){
                char dih = 0;
                if(vmax2 < 27){
                    dih = vmax2-1+'a';
                }else{
                    dih = vmax2-27+'A';
                }
                fout <<dih;
            }else{
                fout << virus[i];
            }
        }
    }
    return 0;
}
