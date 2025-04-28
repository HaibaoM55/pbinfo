#include <fstream>
#include <bitset>
using namespace std;
ifstream fin("triprime.in");
ofstream fout("triprime.out");
int a, b;
bitset<65000004> ciur;
int prime[10000004];
int nrp;
int main(){
    fin >> a >> b;
    for(int i = 2; i <= b/6; i++){
        if(ciur[i] == false){
            nrp++;
            prime[nrp] = i;
            int x = b/(i*6);
            for(int j = i; j <= x; j++){
                ciur[j*i] = true;
            }
        }
    }
    int nr = 0;
    for(int i = 1; i <= nrp-2; i++){
        for(int j = i+1; j <= nrp-1; j++){
            long long p = (long long) prime[i]*prime[j];
            if(p > b/prime[j+1]){
                break;
            }
            int p1 = j+1, p2 = nrp, poza=-1;
            while(p1 <= p2){
                int mij = (p1+p2)/2;
                if(p*prime[mij] < a){
                    p1 = mij+1;
                }else{
                    p2 = mij-1;
                    poza = mij;
                }
            }
            p1 = j+1;
            p2 = nrp;
            int pozb = -1;
            while(p1 <= p2){
                int mij = (p1+p2)/2;
                if(p*prime[mij] > b){
                    p2 = mij-1;
                }else{
                    p1 = mij+1;
                    pozb = mij;
                }
            }
            nr += pozb-poza+1;
        }
    }
    fout << nr;
    return 0;
}
