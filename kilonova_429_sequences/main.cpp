#include <iostream>
using namespace std;
#define MOD 1000000007
int n;
int v[200004];
int f[1000004];
long long c[1000006], p[1000006];
long long res = 0;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin>>n;
    p[0]=0;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        p[i] = p[i-1]+v[i];
    }
    long long m =0;
    long long res =0;
    for(int j = (1<<20);j > 0;j/=2){
        res = res-(m*j);
        res = res%MOD;
        for(int i=1;i<=n;i++){
            c[p[i]%j]++;
            m = 0;
        }
        for(int i=1;i<=n;i++){
            m += c[p[i-1] % j];
            c[p[i]%j]--;
        }
        res = (res+(m*j))%MOD;
    }
    cout<<res%MOD<<endl;
    return 0;
}
