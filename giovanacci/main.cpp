#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("giovanacci.in");
ofstream fout("giovanacci.out");
long long t, p, x;
int n, z;
int f[400004];
int main(){
    fin >> t >> p;
    f[1] = 1;
    f[2] = 1;
    for(z = 3; z <= 4*p; z++){
        f[z] = f[z-1]+f[z-2];
        f[z] = f[z]%p;
        if(f[z] == 1 && f[z-1] == 1){
            z--;
            z--;
            break;
        }
    }
    for(int j = 1; j <= t; j++){
        fin >> n;
        long long g;
        for(int i = 1; i <= n; i++){
            fin >> x;
            if(i == 1){
                g = x;
            }else{
                g = __gcd(x, g);
            }
        }
        g= g%z;
        fout << f[g] << '\n';
    }
    return 0;
}
