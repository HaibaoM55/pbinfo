#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("cmmdc.in");
ofstream fout("cmmdc.out");
int t, n;
long long a[100004];
long long p[100004], s[100004];
int main()
{
    fin >> t;
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> a[i];
    }
    long long cmmdc = a[1];
    int chng = 0;
    for(int i = 2; i <= n; i++){
        long long ics = __gcd(cmmdc, a[i]);
        if(ics < cmmdc){
            chng = i;
        }
        cmmdc = ics;
    }
    if(t == 1){
        fout << cmmdc;
    }else if(t == 2){
        for(int i = 1; i <= n; i++){
            p[i] = __gcd(p[i - 1], a[i]);
        }
        for (int i = n; i >= 1; i--){
            s[i] = __gcd(s[i + 1], a[i]);
        }
        long long vmax = 0;
        for (int i = 1; i <= n; i++){
            vmax = max(vmax, __gcd(p[i - 1], s[i + 1]));
        }
        fout << vmax;
    }else{
        for (int i = 1; i <= n; i++){
            p[i] = __gcd(p[i - 1], a[i]);
        }
        for (int i = n; i >= 1; i--){
            s[i] = __gcd(s[i + 1], a[i]);
        }
        long long vmax = 0;
        for (int i = 1; i < n; i++){
            long long k = 0;
            for (int j = i + 1; j <= n; j++){
                long long t;
                t = __gcd(p[i - 1], s[j + 1]);
                t = __gcd(t, k);
                k = __gcd(k, a[j]);
                vmax = max(vmax, t);
            }
        }
        fout << vmax;
    }
    return 0;
}
