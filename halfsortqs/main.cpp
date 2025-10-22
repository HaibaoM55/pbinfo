#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("halfsortqs.in");
ofstream fout("halfsortqs.out");
int n, x;
int nrp=0, nrn=0;
bool pozitiv[100004];
int pozitive[100004], negative[100004];
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> x;
        if(x > 0){
            nrp++;
            pozitiv[i] = true;
            pozitive[nrp] = x;
        }else{
            nrn++;
            pozitiv[i] = false;
            negative[nrn] = x;
        }
    }
    sort(pozitive+1, pozitive+nrp+1);
    sort(negative+1, negative+nrn+1);
    nrn = 1;
    for(int i = 1; i <= n; i++){
        if(pozitiv[i]){
            fout << pozitive[nrp];
            nrp--;
        }else{
            fout << negative[nrn];
            nrn++;
        }
        fout << ' ';
    }
}
