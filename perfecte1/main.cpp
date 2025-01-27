#include <iostream>
#include <math.h>
using namespace std;
int q;
unsigned int l, r, a, b;
unsigned int pp[44750];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> q;
    for(int i = 1; i <= q; i++){
        cin >> l >> r >> a >> b;
        int x = b-a;
        int nr = 0;
        for(int d = 1; d*d < x; d++){
            if(x % d == 0){
                unsigned int s = d+(b-a)/d;
                if(s % 2 == 0){
					long long k2 = (d+(b-a)/d)/2;
                    long long p = k2*k2-b;
                    if(p >= l && p <= r){
                    	nr++;
                    }
                }
           	}
        }
        cout << nr << '\n';
    }
    return 0;
}
