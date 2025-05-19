#include <fstream>
using namespace std;
ifstream fin("primxxl.in");
ofstream fout("primxxl.out");
int n, k, x;
int ek[1000004];
bool ciur[1000004];
int prm[100004], nrp=0;
int main()
{
    fin >> n >> k;
    for(int i = 2; i <= 1000000; i++){
        if(ciur[i] == false){
            nrp++;
            prm[nrp] = i;
            for(int j = i; j <= 1000000/i; j++){
                ciur[j*i] = true;
            }
        }
    }
    for(int i = 1; i <= nrp && prm[i] <= k; i++){
        int p = k;
        int s = 0;
        while(p >= prm[i]){
            p = p/prm[i];
            s += p;
        }
        ek[prm[i]] = s;
    }
    int nr = 0;
    for(int i = 1; i <= n; i++){
        fin >> x;
        bool ok = true;
        for(int j = 1; j <= nrp && prm[j]*prm[j] <= x; j++){
            int f = 0;
            while(x % prm[j] == 0){
                x = x/prm[j];
                f++;
            }
            if(f > ek[prm[j]]){
                ok = false;
                break;
            }
        }
        if(x > k){
            ok = false;
        }
        if(ok){
            nr++;
        }
    }
    fout << nr;
    return 0;
}
