#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("masina.in");
ofstream fout("masina.out");
int v[1001],n,ok,nr,r,d,k;
int main(){
    fin >> d >> r >> k;
    ok = 1;
    for(int i = 1; i <= k; i++){
        fin >> v[i];
        if(v[i] - v[i-1] > r){
            ok = 0;
        }
    }
    if(ok==0 || v[k]+r < d){
        fout << -1;
    }else{
        n+=r;
        while(n < d){
            int i;
            for(i = 1; i <= k; i++){
                if(v[i] > n){
                    break;
                }
            }
            i--;
            n = v[i];
            n += r;
            nr++;
        }
        fout<<nr;
    }
    return 0;
}
