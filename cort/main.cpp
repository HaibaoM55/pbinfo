#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("cort.in");
ofstream fout("cort.out");
int c;
int n, m;
int f[1004];
bool x;
int main()
{
    fin >> c;
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            fin >> x;
            if(x){
                f[i]++;
            }
        }
    }
    if(c == 1){
        int nr = 0;
        for(int i = 1; i <= n; i++){
            if(f[i] > 0){
                nr++;
            }
        }
        fout << nr;
    }else{
        sort(f+1, f+n+1);
        int vmax = 0;
        for(int i = n; i >= 1; i--){
            vmax = max(vmax,(n-i+1)*f[i]);
        }
        fout << vmax;
    }
    return 0;
}
