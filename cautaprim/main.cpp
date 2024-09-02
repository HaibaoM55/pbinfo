#include <fstream>
using namespace std;
ifstream fin("cautaprim.in");
ofstream fout("cautaprim.out");
int n, x;
bool f[105], ciur[105];
int prime[51];
int nrp = 0;
int main()
{

    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> x;
        f[x] = true;
    }
    for(int i = 2; i <= 99; i++){
        if(ciur[i] == false){
            if(i > 10){
                nrp++;
                prime[nrp] = i;
            }
            for(int j = 2*i; j <= 99; j += i){
                ciur[j] = true;
            }
        }
    }
    for(int i = nrp; i >= 1; i--){
        if(f[prime[i]] == false){
            fout << prime[i];
            return 0;
        }
    }
    fout << 0;
    return 0;
}
