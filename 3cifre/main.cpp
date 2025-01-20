#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("3cifre.in");
ofstream fout("3cifre.out");
int n, c;
char x[12];
unsigned int vmin=1000, vminap, vmini, vminj;
unsigned int vmax=0, vmaxap, vmaxi, vmaxj;
int f[1000];
int main()
{
    fin >> n >> c;
    for(int i = 1; i <= n; i++){
        fin >> x;
        long long z = 0;
        int l = strlen(x);
        for(int j = 0; j < l; j++){
            z = z*10 + x[j]-'0';
        }
        int y = x[0]*100+x[1]*10+x[2];
        if(l >= 3){
            for(int j = 2; j < l; j++){
                if(x[j-2] != '0'){
                    int y = (x[j-2]-'0')*100+(x[j-1]-'0')*10+(x[j]-'0');
                    if(y < vmin){
                        vmin = y;
                        vmini = z;
                        vminap = 1;
                        vminj = z;
                    }else if(y == vmin){
                        vminj = z;
                        vminap++;
                    }
                    if(y > vmax){
                        vmax = y;
                        vmaxi = z;
                        vmaxap = 1;
                        vmaxj = z;
                    }else if(y == vmax){
                        vmaxj = z;
                        vmaxap++;
                    }
                    f[y]++;
                }
            }
        }
    }
    if(c == 1){
        fout << vmin << ' ' << vminap << ' ' << vmini << ' ' << vminj << '\n';
        fout << vmax << ' ' << vmaxap << ' ' << vmaxi << ' ' << vmaxj;
    }else{
        int vmax = 0;
        for(int i = 100; i < 1000; i++){
            if(f[i] > vmax){
                vmax = f[i];
            }
        }
        fout << vmax << '\n';
        for(int i = 100; i < 1000; i++){
            if(f[i] == vmax){
                fout << i << ' ';
            }
        }
    }
    return 0;
}
