#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("halfsort4.in");
ofstream fout("halfsort4.out");
int n;
int v[1004];
int nrp = 0, nrn = 0;
int poz[1004], neg[1004];
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
        if(v[i] >= 0){
            nrp++;
            poz[nrp] = v[i];
        }else{
            nrn++;
            neg[nrn] = v[i];
        }
    }
    sort(poz+1, poz+nrp+1);
    sort(neg+1, neg+nrn+1);
    nrn = 1;
    for(int i = 1; i <= n; i++){
        if(v[i] >= 0){
            fout << poz[nrp];
            nrp--;
        }else{
            fout << neg[nrn];
            nrn++;
        }
        fout << ' ';
    }
    return 0;
}
