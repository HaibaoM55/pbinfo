#include <fstream>
#include <math.h>
#include <algorithm>
using namespace std;
#pragma GCC optimize("O1")
ifstream fin("pcp.in");
ofstream fout("pcp.out");
long long n;
int fn[12], f[12];
int s[20];
long long v[100004];
int nr =0;
long long r9 =0;
int main()
{
    fin >> n;
    r9 = n%9;
    long long nrf = 1;
    int nrz1 = 0;
    do{
        nrz1++;
        s[nrz1] = n%10;
        fn[n%10]++;
        nrf = nrf*10;
        n = n / 10;
    }while(n > 0);
    sort(s+1, s+nrz1+1);
    long long x=0, y=0;
    for(int i = 1; i <= nrz1; i++){
        x = x * 10 + s[i];
    }
    for(int i = nrz1; i >= 1; i--){
        y = y * 10 + s[i];
    }
    x = sqrt(x);
    y = sqrt(y)+1;
    for(int i = x; i <= y; i++){
        long long pp = 1LL*i*i;
        if(pp % 9 != r9)
            continue;
        for(int j = 0; j <= 9; j++){
            f[j] = 0;
        }
        do{
            f[pp%10]++;
            pp = pp/10;
        }while(pp > 0);
        if(f[0] <= fn[0]){
            bool ok = true;
            for(int j = 1; j <= 9; j++){
                if(f[j] != fn[j]){
                    ok = false;
                    break;
                }
            }
            if(ok){
                nr++;
                v[nr] = 1LL*i*i;
            }
        }
    }
    if(nr > 0){
        fout << nr << '\n';
        for(int i = 1; i <= nr; i++){
            fout << v[i] << '\n';
        }
    }else{
        fout << "nu exista";
    }
    return 0;
}
