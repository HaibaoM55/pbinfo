#include <fstream>
#include <math.h>
using namespace std;
ifstream fin("bomboane2.in");
ofstream fout("bomboane2.out");
int n;
long long vmin = 100004, vmini;
int f[100004];
long long x[100004], k;
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> x[i];
        if(x[i] >= i){
            k = sqrt(1LL * (n + 2 * i) * (n + 2 * i) - 8 * n * (i - x[i]));
            k = k - n - 2 * i;
            k = k / (2 * n);
            k++;
        }else{
            k = 0;
        }
        vmin = min(vmin, k);
    }
    long long s = vmin*n*(vmin*n+1)/2;
    fout << s;
    return 0;
}
