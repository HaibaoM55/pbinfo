#include <iostream>
#include <math.h>
using namespace std;
int n, k;
int main()
{
    cin >> n;
    int sq = sqrt(2*n)+1;
    int x = n;
    for(k = 1; k <= sq; k++){
        if(x > k){
            x = x-k;
        }else{
            break;
        }
    }
    cout << k-x+1;
    return 0;
}
