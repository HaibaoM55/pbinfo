#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("pprim.in");
ofstream fout("pprim.out");
int n, p;
int a, b;
int c[33004];
int main()
{
    fin >> n >> p;
    for(int x = 1; x <= 33000; x++){
        int nr = 1;
        for(int d = 2; d*d <= x; d++){
            if(x % d == 0){
                int g = __gcd(d, x/d);
                if(g == 1){
                    nr++;
                    if(nr > p){
                        break;
                    }
                }
            }
        }
        if(nr == p){
            c[x]++;
        }
        c[x] = c[x-1]+c[x];
    }
    int smax=0, smaxa, smaxb;
    for(int i = 1; i <= n; i++){
        fin >> a >> b;
        if(a > b){
            int aux = a;
            a = b;
            b = aux;
        }
        int s = c[b]-c[a-1];
        if(s > smax){
            smax = s;
            smaxa = a;
            smaxb = b;
        }
    }
    fout << smaxa << ' ' << smaxb;
    return 0;
}
