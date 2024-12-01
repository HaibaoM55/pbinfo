#include <fstream>
using namespace std;
ifstream fin("teatru.in");
ofstream fout("teatru.out");
int n, k;
char x[55005];
int nr = 0;
int nrmax=0;
int nri, nrj;
int f[26];
int main()
{
    fin >> n >> k;
    for(int i = 1; i <= n; i++){
        fin >> x[i];

    }
    nr = 0;
    int i = 1;
    for(int j = 1; j <= n; j++){
        if(f[x[j]-'A'] == 0){
            nr++;
            f[x[j]-'A']++;
            while(nr > k){
                f[x[i]-'A']--;
                if(f[x[i]-'A'] == 0){
                    nr--;
                }
                i++;
            }
        }else{
            f[x[j]-'A']++;
        }
        if(nr <= k && j-i+1 > nrmax){
            nrmax = j-i+1;
            nri = i;
            nrj = j;
        }
    }
    fout << nrmax << '\n';
    for(int i = nri; i <= nrj; i++){
        fout << x[i];
    }
    return 0;
}
