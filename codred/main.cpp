#include <iostream>
using namespace std;
#define MOD 1000000007
unsigned long long s = 0;
long long fact = 1;
int n;
int main(){
    cin >> n;
    if(n >= 5000000){
        fact = 179975082LL;
        for(int i = 5000001; i <= n; i++){
            fact = 1LL*fact*(i+1);
            fact = fact%MOD;
        }
    }else{
        for(int i = 1; i <= n; i++){
            fact = 1LL*fact*(i+1);
            fact = fact%MOD;
        }
    }
    s = s+(((n+1)*fact)%MOD)-1;
    s = s%MOD;
    cout << s;
    return 0;
}
