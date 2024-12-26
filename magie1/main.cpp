#include <fstream>
using namespace std;
ifstream fin("magie.in");
ofstream fout("magie.out");
int c, n, v[5003];
int fmax =0,f[10003];
int vmax = 0;
int main()
{
    fin >> c;
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >>v[i];
    }
    if(c == 1){
        for(int i = 1; i <= n; i++){
            f[v[i]]++;
            if(f[v[i]] > fmax){
                fmax = f[v[i]];
            }
        }
        fout << fmax;
    }
    else if(c == 2){
        int x;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= v[i]; j++){
                if(j == 0){
                    x = v[i];
                }
                else{
                    if(v[i]%j == 0){
                        x = v[i]+j;
                    }else{
                        continue;
                    }
                }
                int l = 1;
                for(int p = i+1; p <= n; p++){
                    if((v[p] > x) || (2*v[p] < x)){
                        break;
                    }else{
                        bool ok = false;
                        if((v[p] == x) || (v[p]%(x-v[p]) == 0)){
                            ok = true;
                        }
                        if(ok){
                            l++;
                        }else{
                            break;
                        }
                    }
                }
                for(int p = i-1; p >= 1; p--){
                    if((v[p] > x) || (2*v[p] < x)){
                        break;
                    }else{
                        bool ok = false;
                        if((v[p] == x) || (v[p]%(x-v[p]) == 0)){
                            ok = true;
                        }
                        if(ok){
                            l++;
                        }else{
                            break;
                        }
                    }
                }
                if(l > vmax){
                    vmax = l;
                }
            }
        }
        fout << vmax;
    }
    else if(c == 3){
        for(int i = 1; i <= n; i++){
            f[v[i]]++;
            for(int d = 1; d <= v[i]; d++){
                if(v[i] % d == 0){
                    f[v[i] + d]++;
                }
            }
        }
        vmax = 0;
        for(int i = 1; i <= 10000; i++){
            vmax = max(vmax, f[i]);
        }
        fout << vmax;
    }
    return 0;
}
