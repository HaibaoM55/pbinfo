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
    for(int i = 1; i <= 44733; i++){
        pp[i] = i*i;
    }
    cin >> q;
    for(int i = 1; i <= q; i++){
        cin >> l >> r >> a >> b;
        int p2 = sqrt(l+b);
        unsigned int nr = 0;
        for(int j = p2; j <= 44733 && pp[j] <= r+b; j++){
            if(pp[j] >= l+b){
                unsigned int x = pp[j]-b+a;
                unsigned int sq = sqrt(x);
                if(sq*sq == x && x >= l+a){
                    nr++;
                }
            }
        }
        cout << nr << '\n';
    }
    return 0;
}
