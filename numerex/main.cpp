#include <fstream>
using namespace std;
ifstream fin("numere.in");
ofstream fout("numere.out");
long long c;
long long n,m,t;
long long vmax = 0, vmaxi = 0;
long long ciur[100004];
long long s[100004], v[100004];
int main()
{
    fin >> c;
    fin >> n;
    for(int i = 2; i <= n; i++){
        if(ciur[i] > vmax){
            vmax = ciur[i];
            vmaxi = i;
        }
        for(int j = 2; j <= n/i; j++){
            ciur[j*i]++;
        }
    }
    if(c == 1){
        fout << vmaxi;
    }else{
        fin >> m >> t;
        s[0] = 0;
        v[0] = 1;
        for(int i = 1; i <= n; i++){
            if(ciur[i] == t){
                s[i] = 1;
            }else{
                s[i] = 0;
            }
            s[i] = s[i-1]+s[i];
            v[s[i]]++;
        }
        long long nr = 0;
        for(int i = 0; i <= s[n]-m; i++){
            nr = nr+(1LL*v[i+m]*v[i]);
        }
        fout << nr;
    }
    return 0;
}
