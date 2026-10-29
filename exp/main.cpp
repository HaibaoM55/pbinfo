#include <fstream>
using namespace std;
ifstream fin("expresie.in");
ofstream fout("expresie.out");
int n, m, x;
int ex[30004];
bool ciur[204];
int prm[204], nrp =0;
int main(){
    fin >> m;
    fin >> n;
    for(int i = 2; i <= 204; i++){
        if(ciur[i] == false){
            nrp++;
            prm[nrp] = i;
            for(int j = i; j <= 204/i; j++){
                ciur[j*i] = true;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        fin >> x;
        for(int j = 1; prm[j]*prm[j] <= x && j <= nrp; j++){
            while(x % prm[j] == 0){
                ex[prm[j]]++;
                x = x/prm[j];
            }
        }
        ex[x]++;
    }
    bool mergeok = true;
    for(int i = 2; i <= 30000; i++){
        if(ex[i] % m == 0){
            ex[i] = ex[i]/m;
        }else{
            mergeok = false;
            break;
        }
    }
    if(mergeok){
        fout << "1\n";
        for(int i = 2; i <= 30000; i++){
            if(ex[i] > 0){
                fout << i << ' ' << ex[i] << '\n';
            }
        }
    }else{
        fout << 0;
    }
    return 0;
}
