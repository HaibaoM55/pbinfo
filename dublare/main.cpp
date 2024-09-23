#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
char x[260];
bool esteput2(int x){
    int z = x;
    while(z % 2 == 0){
        z = z/2;
    }
    if(z > 1){
        return false;
    }
    return true;
}
int main()
{
    cin >> x;
    int l = strlen(x);
    for(int i = 1; i < l; i++){
        int vm = l/(i+1);
        if(esteput2(vm) && l % (i+1) == 0){
            bool ok = true;
            int nr = 0;
            while(ok){
                nr++;
                int oi = i;
                for(int j = i+1; j <= 2*i; j++){
                    if(x[j] != x[oi]){
                        ok = false;
                    }
                    oi--;
                }
                i = 2*i+1;
                if(i > l){
                    cout << nr-1;
                    return 0;
                }
            }
        }
    }
    return 0;
}
