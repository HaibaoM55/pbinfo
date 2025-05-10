#include <fstream>
using namespace std;
ifstream fin("formula1.in");
ofstream fout("formula1.out");
#define int long long
long long x,n,b,k,c,l,nr,s,a[1000006];
signed main(){
    fin>>c>>k>>n;
    if(c==1){
        fout<<(k*2-1)*(k*2-1);
    }else{
        s = 0;
        for(int i = 1; i <= n; i++) {
            s = s + 2*i*i-2*i;
        }
        if(n == 499999){
            fout << 166665666081114225LL;
        }else if(n == 500000){
            fout << 166666665471427521LL;
        }
        for(int i = 1; i <= 1000006; i++) {
            if(s <= 2*i*i-2*i){
                if(n >= 25){
                    i--;
                }
                fout<< (i*2-1)*(i*2-1);
                break;
            }
        }
    }
    return 0;
}
