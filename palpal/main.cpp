#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("palpal.in");
ofstream fout("palpal.out");
int n;
char x[20004];
struct benone{
    int x, y;
}par[20004], impar[20004];
int nrp = 0, nri = 0;
int main(){
    fin >> x;
    fin >> n;
    int l = strlen(x);
    fout << l << '\n';
    for(int i = 0; i < l-1; i++){
        if(x[i]== x[i+1]){
            nrp++;
            par[nrp].x = i;
            par[nrp].y = i+1;
        }
    }
    for(int i = 0; i < l-2; i++){
        if(x[i] == x[i+2]){
            nri++;
            impar[nri].x = i;
            impar[nri].y = i+2;
        }
    }
    if(n >= 2){
        fout << nrp << '\n';
    }
    if(n >= 3){
        fout << nri << '\n';
    }
    for(int i = 4; i <= n; i++){
        int nr = 0;
        if(i % 2 == 0){
            for(int j = 1; j <= nrp; j++){
                if(par[j].x == 0 || par[j].y == l-1){
                    par[j].x = 0;
                    par[j].y = 0;
                }
                if(par[j].x == 0 && par[j].y == 0){
                    continue;
                }
                if(x[par[j].x-1] == x[par[j].y+1]){
                    nr++;
                    par[j].x--;
                    par[j].y++;
                }else{
                    par[j].x = 0;
                    par[j].y = 0;
                }
            }
        }else{
            for(int j = 1; j <= nri; j++){
                if(impar[j].x == 0 || impar[j].y == l-1){
                    impar[j].x = 0;
                    impar[j].y = 0;
                }
                if(impar[j].x == 0 && impar[j].y == 0){
                    continue;
                }
                if(x[impar[j].x-1] == x[impar[j].y+1]){
                    nr++;
                    impar[j].x--;
                    impar[j].y++;
                }else{
                    impar[j].x = 0;
                    impar[j].y = 0;
                }
            }
        }
        fout << nr << '\n';
    }
    return 0;
}
