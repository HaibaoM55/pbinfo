#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("prodnr.in");
ofstream fout("prodnr.out");
char x[30004];
bool ciur[100004];
int prm[15004], nrp=0;
int e[100004];
int main()
{
    for(int i = 2; i <= 100000; i++){
        if(ciur[i] == false){
            nrp++;
            prm[nrp] = i;
            for(int j = i; j <= 100000/i; j++){
                ciur[j*i] = true;
            }
        }
    }
    fin >> x;
    int l = strlen(x);
    int nrc = 0;
    for(int i = 0; i < l; i++){
        int nrl = x[i]-'0';
        int nr = 0;
        nrc++;
        while(nrl > 0){
            i++;
            nr = nr*10+x[i]-'0';
            nrl--;
        }
        for(int j = 1; j <= nrp && prm[j]*prm[j] <= nr; j++){
            while(nr % prm[j] == 0){
                nr= nr/prm[j];
                e[prm[j]]++;
            }
        }
        if(nr > 1){
            e[nr]++;
        }
    }
    fout << nrc << '\n';
    for(int i = 2; i <= 100000; i++){
        if(e[i] > 0){
            fout << i << ' ' << e[i] << '\n';
        }
    }
    return 0;
}
