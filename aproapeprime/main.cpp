#include <iostream>
using namespace std;
long long n, nrp = 0, prim[40005];
bool ciur[100005];
bool f[100005];
int main()
{
    for(int i = 2; i <= 100000; i++){
        if(ciur[i] == false){
            nrp++;
            prim[nrp] = i;
            for(int j = 2*i; j <= 100000; j+=i){
                ciur[j] = true;
            }
        }
    }
    for(int i = 1; i <= nrp; i++){
        for(int j = i; j <= nrp; j++){
            long long p = prim[i]*prim[j];
            if(p <= 100000){
                f[p] = true;
            }else{
                break;
            }
        }
    }
    cin >> n;
    int nrx = 0;
    for(int i = 4; i <= 100000; i++){
        if(f[i]){
            nrx++;
        }
        if(nrx == n){
            cout << i;
            break;
        }
    }
    return 0;
}
