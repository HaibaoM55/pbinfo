#include <fstream>
using namespace std;
ifstream fin("nextprime.in");
ofstream fout("nextprime.out");
int n;
bool ciur[1000004];
int nrp=0, prm[78500];
bool esteprim(long long x){
    if(x <= 1){
        return false;
    }
    for(int i = 1; 1LL*prm[i]*prm[i] <= x && i <= nrp; i++){
        if(x % prm[i] == 0){
            return false;
        }
    }
    return true;
}
int main(){
    for(int i = 2; i <= 1000000; i++){
        if(!ciur[i]){
            nrp++;
            prm[nrp] = i;
            for(int j = i; j <= 1000000/i; j++){
                ciur[i*j] = true;
            }
        }
    }
    //fout << nrp << ' ' << prm[nrp] << '\n';
    fin >> n;
    for(int i = 1; i <= n; i++){
        long long nr;
        fin >> nr;
        nr++;
        while(!esteprim(nr)){
            nr++;
        }
        fout << nr << '\n';
    }
    return 0;
}
