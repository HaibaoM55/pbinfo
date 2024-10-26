#include <iostream>
#include <math.h>
using namespace std;
int n, k1, k2;
int main()
{
    cin >> n;
    for(int i = 1; i*i <= n; i++){
        k1 = i*i;
        k2 = n-k1;
        int sq = sqrt(k2);
        if(k1 <= k2){
            if(sq*sq == k2){
                cout << i << ' ' << sq  << '\n';
            }
        }else{
            break;
        }
    }
    return 0;
}
