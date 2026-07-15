#include <fstream>
#include <algorithm>
using namespace std;
#define MOD 1000000007
ifstream cin("amadeus.in");
ofstream cout("amadeus.out");
int n, nr=0;  
int v[14];
int main(){
    cin >> n;
    if(n <= 10){
        for(int i = 1; i <= n; i++){
            v[i] = i;
        }
        do{
            bool ok = true;
            for(int i = 1; i <= n; i++){
                if(v[i] == i){
                    ok = false;
                    break;
                }
            }
            if(ok){
                nr++;
            }
        }while(next_permutation(v+1, v+n+1));
        cout << nr;
    }else{
        int vm1 = 1334961;
        int vm2 = 133496;
        for(int i = 11; i <= n; i++){
            long long x = (vm1+vm2)%MOD;
            x = 1LL*x*(i-1);
            x = x%MOD;
            vm2 = vm1;
            vm1 = x;
        }
        cout << vm1;
    }
    return 0;
}
