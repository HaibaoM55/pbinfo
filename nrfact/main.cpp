#include <iostream>
using namespace std;
int n, x, f, nrfmax;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x;
        int ox = x;
        int nrf = 0;
        for(int j = 2; j*j <= x; j++){
            if(x % j == 0){
                nrf++;
                while(x % j == 0){
                    x = x/j;
                }
            }
        }
        if(x > 1){
            nrf++;
        }
        if(nrf > nrfmax){
            nrfmax = nrf;
            f = ox;
        }else if(nrf == nrfmax){
            f = min(f, ox);
        }
    }
    cout << f;
    return 0;
}
