#include <fstream>
using namespace std;
ifstream fin("bazaf.in");
ofstream fout("bazaf.out");
int v;
long long x;
long long fact[24];
long long f[100004];
int m;
long long prm = 0;
int main()
{
    fin >> v;
    if(v == 1){
        fin >> x;
        fact[1] = 1;
        for(int i = 2; i <= 20; i++){
            fact[i] = fact[i-1]*i;
        }
        for(int i = 20; i >= 1; i--){
            if(x >= fact[i]){
                if(prm == 0){
                    prm = i;
                }
                f[i] = x/fact[i];
                x = x%fact[i];
            }else{
                f[i] = 0;
            }
        }
        fout << prm << ' ';
        for(int i = 1; i <= prm; i++){
            fout << f[i] <<" ";
        }
    }else{
        fin >> m;
        for(int i = 1; i <= m; i++){
            fin >> f[i];
        }
        for(int i = 2; i <= 1000001; i++){
            f[i] = f[i]+f[i-1]/i;
            f[i-1] = f[i-1]%i;
            if(f[i] == 0 && i > m){
                prm = i-1;
                break;
            }
        }
        fout << prm << ' ';
        for(int i = 1; i <= prm; i++){
            fout << f[i] << " ";
        }
    }
    return 0;
}
