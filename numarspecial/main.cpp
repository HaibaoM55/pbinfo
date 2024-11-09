#include <fstream>
using namespace std;
ifstream fin("numarspecial.in");
ofstream fout("numarspecial.out");
int n;
int v[1000004];
int nro0=0, nro1=0;
int nromax = 0;
bool ciur[1000004];
int main()
{
    fin >> n;
    ciur[1] = true;
    for(int i = 2; i <= 1000000; i++){
        if(ciur[i] == false){
            for(int j = i; j <= 1000000/i; j++){
                ciur[i*j] = true;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    for(int i = 1; i <= n; i++){
        if(v[i] % 9 == 0){
            int ka = 0;
            for(int k = 1; i-k >= 1 && i+k <= n; k++){
                if(ciur[v[i-k]] == false && ciur[v[i+k]] == false){
                    ka++;
                }else{
                    break;
                }
            }
            if(ka >= 0){
                nro0++;
            }
            if(ka >= 1){
                nro1++;
            }
            nromax = max(nromax, ka);
        }
    }
    fout << nro0 << '\n';
    fout << nro1 << '\n';
    fout << nromax;
    return 0;
}
