#include <fstream>
using namespace std;
ifstream fin("cardinal.in");
ofstream fout("cardinal.out");
int ciur[32004];
int n,p,nr=1;
int numar;
int pz(int a,int n){
    if(n==0){
        return 1;
    }
    int aux=pz(a,n/2);
    if(n%2==1){
        return aux*aux*a;
    }else{
        return aux*aux;
    }
}
int main()
{
    fin >> n >> p;
    p++;
    while(pz(nr,p)<=n){
        nr++;
    }
    nr--;
    numar=n-1;
    for(int i = 2; i <= nr; i++){
        if(ciur[i]==0){
            for(int j = i; j <= nr; j+=i){
                ciur[j]++;
            }
            for(int j = i*i; j <= nr; j+=i*i){
                ciur[j]=-1e9;
            }
        }
        if(ciur[i] >= 0){
            if(ciur[i] % 2 ==1){
                numar -= n/pz(i,p);
            }else{
                numar += n/pz(i,p);
            }
        }
    }
    fout << numar;
    return 0;
}
