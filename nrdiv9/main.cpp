#include <fstream>
using namespace std;
ifstream fin("nrdiv9.in");
ofstream fout("nrdiv9.out");
int n;
bool ciur[32004];
int nrp = 0, cnt;
int prm[32004];
int main()
{
    fin >> n;
    for(int i = 2; i <= 32000; i++){
        if(ciur[i] == false){
            nrp++;
            prm[nrp] = i;
            for(int j = i; j*i <= 32000; j++){
                ciur[j*i] = true;
            }
        }
    }
    for(int i = 1; i <= nrp-1; i++){
        for(int j = i+1; j <= nrp; j++){
            long long s = prm[i]*prm[i];
            s = s*prm[j]*prm[j];
            if(s <= n){
                cnt++;
            }else{
                break;
            }
        }
    }
    for(int i = 1; i <= 13; i++){
        long long z = prm[i]*prm[i];
        z = z*z;
        z = z*z;
        if(z <= n){
            cnt++;
        }
    }
    fout << cnt;
    return 0;
}
