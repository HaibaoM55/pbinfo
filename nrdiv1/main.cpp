#include <fstream>
using namespace std;
ifstream fin("nrdiv.in");
ofstream fout("nrdiv.out");
int n;
long long x;
bool b[3162280];
int prm[700004], nrp=0;
int main()
{
    fin >> n;
    for(int i = 2; i <= 3162280; i++){
        if(b[i] == false){
            nrp++;
            prm[nrp] = i;
            for(int j = i; j<= 3162280/i; j++){
                b[j*i] = true;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        fin >> x;
        int nrdiv = 1;
        for(int j = 1; j <= nrp && prm[j] <= x; j++){
            if(x % prm[j] == 0){
                int p = 0;
                while(x % prm[j] == 0){
                    x = x / prm[j];
                    p++;
                }
                nrdiv = nrdiv*(p+1);
            }
        }
        if(x > 1){
            nrdiv = nrdiv*2;
        }
        fout << nrdiv << '\n';
    }
    return 0;
}
