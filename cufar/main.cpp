#include <fstream>
using namespace std;
ifstream fin("cufar.in");
ofstream fout("cufar.out");
int p, n;
int x, y;
bool ciur[1000004];
int prm[1000004];
int nrp = 0;
int main()
{
    fin >> p >> n;
    for(int i = 2; i <= 1000000; i++){
        if(ciur[i] == false){
            nrp++;
            prm[nrp] = i;
            for(int j = i; j <= 1000000/i; j++){
                ciur[j*i] = true;
            }
        }
    }
    if(p == 1){
        for(int i = 1; i <= n; i++){
            fin >> x >> y;
            int k = 0;
            for(int j = 1; j <= nrp && prm[j] <= x; j++){
                if(x % prm[j] == 0){
                    x = x / prm[j];
                    k++;
                    if(k == y){
                        fout << prm[j] << '\n';
                        break;
                    }
                }
            }
        }
    }else{
        long long nr = 0;
        for(int i = 1; i <= n; i++){
            fin >> x >> y;
            int k = 0;
            bool ok = true;
            for(int j = 1; j <= nrp && prm[j]*prm[j] <= x; j++){
                if(x % prm[j] == 0){
                    while(x % prm[j] == 0){
                        x = x / prm[j];
                    }
                    k++;
                    if(k == y){
                        nr += prm[j];
                        ok = false;
                        break;
                    }
                }
            }
            if(ok){
                nr += x;
            }
        }
        fout << nr;
    }
    return 0;
}
