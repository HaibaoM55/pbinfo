#include <fstream>
using namespace std;
ifstream fin("bomboane3.in");
ofstream fout("bomboane3.out");
int p, n;
int v[10004], a[100004];
int vmin = 1e9;
int main()
{
    fin >> p >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
        vmin = min(vmin, v[i]);
    }
    if(p == 1){
        for(int i = vmin; i >= 1; i--){
            bool ok = true;
            for(int j = 2; j <= n; j++){
                if(v[j]%i != v[1]%i){
                    ok = false;
                    break;
                }
            }
            if(ok){
                fout << i;
                return 0;
            }
        }
    }else{
        for(int xk = 1; xk <= n; xk++){
            int x = v[xk];
            int i = 0;
            while(i <= x-1){
                i++;
                x -= i;
                a[i] = i;
            }
            a[i] += x;
            int z = i, j;
            fout << i << ' ';
            for(j = 1; j <= i/2; j++){
                fout << a[j] << ' ' << a[z] << ' ';
                z--;
            }
            if(z == j){
                fout << a[j];
            }
            fout << '\n';
        }
    }
    return 0;
}
