#include <iostream>
using namespace std;
int x;
int f[67];
int o;
int main(){
    int nr =0;
    o = -1;
    while(cin >> x){
        if(x == 0){
        	break;
        }
        int p = x%10;
        if(p < 0){
            p = -p;
        }
        if(o == p){
            nr++;
        }
        o = p;
    }
    cout << nr;
    return 0;
}
