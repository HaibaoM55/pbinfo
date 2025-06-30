#include <fstream>
using namespace std;
ifstream fin("secventa3.in");
ofstream fout("secventa3.out");
int n, x;
int vmax=0, vmaxj=0;
int main(){
    fin >> n;
    int nr = 1, pt = 0;
    for(int i = 1; i <= n; i++){
        fin >> x;
        if(x % 2 != pt){
            nr++;
        }else{
            nr = 1;
        }
        if(i == 1){
            nr = 1;
        }
        pt = x%2;
        if(vmax <= nr){
            vmax = nr;
            vmaxj = i;
        }
    }
    fout << vmaxj-vmax+1 << ' ' << vmaxj;
    return 0;
}
