#include <fstream>
using namespace std;
ifstream fin("santinele.in");
ofstream fout("santinele.out");
int c;
int n, k;
int v[100004];
int kmax = 0;
int main()
{
    fin >> c;
    fin >> n >> k;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    if(c == 1){
        for(int i = 1; i <= k+1; i++){
            int kk1 = 0;
            for(int j = i-1; j >= 1 && j >= i-k; j--){
                if(v[j] <= v[i]){
                    kk1++;
                }else{
                    break;
                }
            }
            int kk2 = 0;
            for(int j = i+1; j <= n && j <= i+k; j++){
                if(v[j] <= v[i]){
                    kk2++;
                }else{
                    break;
                }
            }
            kmax = max(kmax, kk1+kk2+1);
        }
        fout << kmax;
    }else{
        int nri = 1;
        int nr = 0;
        while(nri <= n){
            int nrmax = 0, nrmaxi=0;
            for(int i = nri; i <= nri+k && i <= n; i++){
                if(v[i] >= nrmax){
                    nrmax = v[i];
                    nrmaxi = i;
                }
            }
            nri = nrmaxi+k+1;
            for(int i = nrmaxi+1; i <= nrmaxi+k && i <= n; i++){
                if(v[i] > nrmax){
                    nri = i;
                    break;
                }
            }
            nr++;
        }
        fout << nr;
    }
    return 0;
}
