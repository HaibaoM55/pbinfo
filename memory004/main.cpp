#include <fstream>
#include <bitset>
using namespace std;
ifstream fin("memory004.in");
ofstream fout("memory004.out");
int n, m;
int f[1004];
int x1[1004];
bitset<10004> b;
int x, smax=0;
int main()
{
    fin >> n >> m;
    b[1] = true;
    for(int i = 2; i <= 10000; i++){
        if(b[i] == false){
            for(int j = i; j*i <= 10000; j++){
                b[i*j] = true;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            fin >> x;
            bool ok = !b[x];
            if(ok && x != 1){
                f[j]++;
                smax = max(smax, f[j]);
            }else{
                if(x1[j] == 0){
                    x1[j] = f[j];
                }
                f[j] = 0;
            }
        }
    }
    /*for(int i = 1; i <= m; i++){
        fout << f[i] << ' ' << x1[i] << '\n';
    }
    fout << '\n';*/
    for(int i = 1; i <= m-1; i++){
        int s = 0;
        do{
            s = s+f[i]+x1[i+1];
            i++;
        }while(f[i] == n);
        i--;
        smax = max(smax, s);
    }
    fout << smax;
    return 0;
}
