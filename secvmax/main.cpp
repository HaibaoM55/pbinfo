#include <fstream>
using namespace std;
ifstream fin("secvmax.in");
ofstream fout("secvmax.out");
int n, x;
int vmax = 0, vmaxi = 0, vmaxs = 0;
int main()
{
    fin >> n;
    int scv = 0, sm = 0;
    for(int i = 1; i <= n; i++){
        fin >> x;
        if(x % 2 != 0){
            scv = 0;
            sm= 0;
        }else{
            scv++;
            sm += x;
        }
        if(scv > vmax){
            vmax = scv;
            vmaxi = i;
            vmaxs == sm;
        }else if(scv==vmax){
            if(sm > vmaxs){
                vmaxi=i;
                vmaxs = sm;
            }
        }
    }
    fout << vmaxi-vmax+1 << ' ' << vmaxi;
    return 0;
}
