#include <fstream>
using namespace std;
ifstream cin("exponent.in");
ofstream cout("exponent.out");
int n, a;
int f[401], f1[401];
bool ciur[1001];
int nrp, prm[401];
int vmin = 1000004;
int main()
{
    cin >> n >> a;
    for(int i = 2; i <= 1000; i++){
        if(ciur[i] == false){
            nrp++;
            prm[nrp] = i;
            for(int j = i; j <= 1000/i; j++){
                ciur[i*j] = true;
            }
        }
    }
    for(int j = 1; j <= nrp && prm[j] <= a; j++){
        while(a % prm[j] == 0){
            a = a / prm[j];
            f1[j]++;
        }
    }
    for(int i = 1; i <= n; i++){
        int ilm = i;
        for(int j = 1; j <= nrp && prm[j] <= ilm; j++){
            while(ilm % prm[j] == 0){
                ilm = ilm / prm[j];
                f[j]++;
            }
        }
    }
    for(int i = 1; i <= nrp; i++){
        if(f1[i] == 0){
            continue;
        }
        vmin = min(vmin, f[i]/f1[i]);
    }
    cout << vmin;
    return 0;
}
