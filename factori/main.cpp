#include <fstream>
using namespace std;
ifstream fin("factori.in");
ofstream fout("factori.out");
int n;
bool ciur[60004];
int prm[60004], nrp=0;
int main(){
    for(int i = 2; i <= 60000; i++){
        if(ciur[i]==false){
            nrp++;
            prm[nrp]= i;
            for(int j = i; j <= 60000/i; j++){
                ciur[j*i] = true;
            }
        }
    }
    fin >> n;
    while(n != 0){
        int nr = 0;
        for(int i = 1; i <= nrp && n >= prm[i]; i++){
            nr = 0;
            int p = prm[i];
            while(p <= n){
                nr += n/p;
                p = p*prm[i];
            }
            if(nr == 0){
                break;
            }
            fout << nr << ' ';
        }
        fout << '\n';
        fin >> n;
    }
    return 0;
}
