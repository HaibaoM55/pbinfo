#include <fstream>
using namespace std;
ifstream fin("binar.in");
ofstream fout("binar.out");
int c;
int n, x;
char f[1000004];
int vmax=0, vmaxi=0;
int main()
{
    fin >> c;
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> x;
        f[i] = 0;
        int y = x;
        int fi = 0;
        while(x != 0){
            if(x % 2 == 1){
                fi++;
            }
            x = x/2;
        }
        f[i] = fi;
        if(fi > vmax){
            vmax = f[i];
            vmaxi = y;
        }else if(fi == vmax){
            if(y > vmaxi){
                vmaxi = y;
            }
        }
    }
    if(c == 1){
        fout << vmaxi;
    }else{
        int j = 0;
        int nr = 1;
        f[0] = -1;
        vmax = 1;
        vmaxi = 1;
        for(int i = 1; i <= n; i++){
            if(f[i] == f[i-1]){
                nr++;
                if(nr > vmax){
                    vmax = nr;
                    vmaxi = j;
                }
            }else{
                j = i;
                nr = 1;
            }
        }
        fout << vmax << ' ' << vmaxi;
    }
    return 0;
}
