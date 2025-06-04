#include <fstream>
#include <algorithm>
using namespace std;
#define int long long
ifstream fin("antidivizor.in");
ofstream fout("antidivizor.out");
int t, n;
long long lfact[56], l = 0;
long long cmmmc(long long a, long long b){
    return 1LL*a*b/(__gcd(a, b));
}
signed main(){
    lfact[0]=1;
    while(lfact[l]<=1000000000000000LL){
        l++;
        lfact[l]=cmmmc(lfact[l-1], l);
    }
    l--;
    fin >> t;
    for(int i = 1; i <= t; i++){
        fin >> n;
        long long rasp = 0;
        for(int i=1;i<=l;i++){
            rasp += (i+1)*(n/lfact[i]-n/lfact[i+1]);
        }
        fout << rasp << '\n';
    }
    return 0;
}
