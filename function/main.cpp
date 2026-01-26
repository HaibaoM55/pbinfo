#include <iostream>
using namespace std;
#define MOD 1000000007
#define int long long
int q, y;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> q >> y;
    for(int i = 1; i <= q; i++){
        int st, dr;
        cin >> st >> dr;
        int r;
        if(st == 0){
            int n = dr;
            int A=2;
            int P1=1;
            while(n!=0)
            {
                int c=n%2;
                if(c==1)
                {
                    P1=P1*A;
                    P1=P1%MOD;
                }
                n=n/2;
                A=A*A;
                A=A%MOD;
            }
            r = (y*P1)%MOD;
        }else{
            int n = dr;
            int A=2;
            int P1=1;
            while(n!=0)
            {
                int c=n%2;
                if(c==1)
                {
                    P1=P1*A;
                    P1=P1%MOD;
                }
                n=n/2;
                A=A*A;
                A=A%MOD;
            }
            int drc = P1;
            n = st-1;
            A=2;
            P1=1;
            while(n!=0)
            {
                int c=n%2;
                if(c==1)
                {
                    P1=P1*A;
                    P1=P1%MOD;
                }
                n=n/2;
                A=A*A;
                A=A%MOD;
            }
            int stc = P1;
            long long calc = (drc-stc+MOD)%MOD;
            r = (y*calc)%MOD;
        }
        cout << r << '\n';
    }
    return 0;
}
