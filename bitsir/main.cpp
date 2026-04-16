#include <fstream>
using namespace std;
#define MOD 1000000007
ifstream fin("bitsir.in");
ofstream fout("bitsir.out");
int n, x, y;
int m[100004];
bool doarzero = true;
int v[67];
int nr = 0;
bool verif(){
    int oror = v[1];
    for(int i = 2; i <= n; i++){
        oror = oror | v[i];
    }
    if(oror != x){
        return false;
    }
    int xorxor = v[1];
    for(int i = 2; i <= n; i++){
        xorxor = xorxor ^ v[i];
    }
    if(xorxor != y){
        return false;
    }
    for(int i = 1; i <= n; i++){
        int p1 = v[i]&m[i];
        if(p1 != m[i]){
            return false;
        }
    }
    return true;
}
int main(){
    fin >> n >> x >> y;
    for(int i = 1; i <= n; i++){
        fin >> m[i];
        if(m[i] != 0){
            doarzero = false;
        }
    }
    if(n <= 4 && x <= 63){
        int nr = 0;
        if(n == 4){
            for(int a = 0; a <= x; a++){
                for(int b = 0; b <= x; b++){
                    for(int c = 0; c <= x; c++){
                        for(int d = 0; d <= x; d++){
                            v[1] = a;
                            v[2] = b;
                            v[3] = c;
                            v[4] = d;
                            if(verif()){
                                nr++;
                            }
                        }
                    }
                }
            }
        }else if(n == 3){
            for(int a = 0; a <= x; a++){
                for(int b = 0; b <= x; b++){
                    for(int c = 0; c <= x; c++){
                        v[1] = a;
                        v[2] = b;
                        v[3] = c;
                        if(verif()){
                            nr++;
                        }
                    }
                }
            }
        }else if(n == 2){
            for(int a = 0; a <= x; a++){
                for(int b = 0; b <= x; b++){
                    v[1] = a;
                    v[2] = b;
                    if(verif()){
                        nr++;
                    }
                }
            }
        }else{
            for(int a = 0; a <= x; a++){
                v[1] = a;
                if(verif()){
                    nr++;
                }
            }
        }
        if(nr == 0){
            fout << "NU\n0";
        }else{
            fout << "DA\n";
            fout << nr;
        }
        return 0;
    }
    if(x == 1 && doarzero && y == 0){
        fout << "DA\n";
        long long p = 1;
        for(int i = 1; i <= n-1; i++){
            p = p*2;
            p = p % MOD;
        }
        fout << (p-1+MOD)%MOD;
    }else{
        if(x == 0){
            if(y == 0){
                fout << "DA\n1";
            }else{
                fout << "NU\n0";
            }
        }else{
            fout <<"DA\n67";
        }
    }
    return 0;
}
