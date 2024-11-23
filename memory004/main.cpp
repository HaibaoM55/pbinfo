#include <fstream>
using namespace std;
ifstream fin("memory004.in");
ofstream fout("memory004.out");
int n, m;
int f[1004];
int x, smax=0;
int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            fin >> x;
            bool ok = true;
            for(int k=2; k*k <= x; k++){
                if(x % k == 0){
                    ok = false;
                    break;
                }
            }
            if(ok){
                f[j]++;
                smax = max(smax, f[j]);
            }else{
                f[j] = 0;
            }
        }
    }
    fout << smax;
    return 0;
}
