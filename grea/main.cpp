#include <fstream>
using namespace std;
ifstream fin("grea.in");
ofstream fout("grea.out");
int t, n, nrp = 0;
bool ciur[50004];
int prm[5150];
int main(){
    for(int i = 2; i <= 50000; i++){
        if(ciur[i] == false){
            nrp++;
            prm[nrp] = i;
            for(int j = i; j <= 50000/i; j++){
                ciur[i*j] = true;
            }
        }
    }
    fin >> t;
    for(int pz = 1; pz <= t; pz++){
        fin >> n;
        int k = 0;
        for(int i = 1; prm[i]*prm[i] <= n; i++){
            while(n % prm[i] == 0){
                n = n / prm[i];
                k++;
            }
        }
        if(n != 1){
            k++;
        }
        fout << k << '\n';
    }
    return 0;
}
