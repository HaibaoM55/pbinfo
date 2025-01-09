#include <fstream>
using namespace std;
ifstream fin("maxdiv.in");
ofstream fout("maxdiv.out");
int n, c;
int v[1004];
int f[1004];
int vmax = 0, vmaxi = 0;
int main()
{
    fin >> n >> c;
    for(int i = 1; i <= n; i++){
        int x;
        fin >> x;
        f[i] = x;
        v[i] = 2;
        for(int j = 2; j*j <= x; j++){
            if(x % j == 0){
                v[i]++;
                if(j*j < x){
                    v[i]++;
                }
            }
        }
        if(v[i] > vmax){
            vmax = v[i];
            vmaxi = 1;
        }else if(v[i] == vmax){
            vmaxi++;
        }
    }
    if(c == 1){
        fout << vmaxi-1;
    }else{
        int inc = 0;
        int lgmax = 0, lginc = 0;
        for(int i = 1; i <= n; i++){
            if(v[i] == vmax){
                if(inc == 0){
                    inc = i;
                }else{
                    if(i-inc > lgmax){
                        lgmax = i-inc;
                        lginc = inc;
                    }
                    inc = i;
                }
            }
        }
        for(int i = lginc; i <= lginc+lgmax; i++){
            fout << f[i] << ' ';
        }
    }
    return 0;
}
