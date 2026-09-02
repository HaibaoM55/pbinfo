#include <fstream>
using namespace std;
ifstream fin("sir12.in");
ofstream fout("sir12.out");
int x, nri;
int vmax1=0, vmax2=0;
int main(){
    while(fin >> x){
        if(x % 2 == 1){
        	nri++;
        }
        if(nri == 3 && x % 2 == 0){
            if(x > vmax1){
                vmax2 = vmax1;
            	vmax1 = x;
            }else if(x > vmax2){
            	vmax2 = x;
            }
        }
    }
    if(vmax2 == 0){
        fout << "Nu exista";
        return 0;
    }
    fout << vmax2 << ' ' << vmax1;
    return 0;
}
