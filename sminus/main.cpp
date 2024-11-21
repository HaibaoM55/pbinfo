#include <fstream>
using namespace std;
ifstream fin("sminus.in");
ofstream fout("sminus.out");
int n;
int v[100004];
int vmax = -1004;
int vmaxnr = 0;
int vmaxi=0, vmaxj=0;
bool doarnegative=true;
int sma = 0;
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
        sma = sma+v[i];
        if(v[i] >= 0){
            doarnegative=false;
        }
    }
    if(doarnegative){
        for(int i = 1; i<= n; i++){
            if(v[i] > vmax){
                vmax = v[i];
                vmaxi = i;
                vmaxj = i;
            }
        }
    }else{
        int s = 0;
        int nr = 0;
        for(int i = 1; i <= n; i++){
            if(s+v[i] >= 0){
                s+=v[i];
                nr++;
                if(s > vmax){
                    vmax = s;
                    vmaxnr = nr;
                    vmaxi = i-nr+1;
                    vmaxj = i;
                }
            }else{
                s=0;
                nr=0;
            }
        }
    }
    fout << vmaxi << ' '<<vmaxj <<'\n';
    fout << sma-2*vmax;
    return 0;
}
