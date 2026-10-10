#include <fstream>
using namespace std;
#define MOD 666013
ifstream fin("100m.in");
ofstream fout("100m.out");
int n;
long long rasp[5004];
long long raspuns = 0;
int main(){
    fin >> n;
    rasp[1] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = i; j >= 1; j--){
            rasp[j] = rasp[j-1]+rasp[j];
            rasp[j] = rasp[j]%MOD;
            rasp[j] = rasp[j]*j;
            rasp[j] = rasp[j]%MOD;
        }
    }
    for(int i = 1; i <= n; i++){
        raspuns += rasp[i];
        raspuns = raspuns%MOD;
    }
    fout << raspuns;
    return 0;
}
