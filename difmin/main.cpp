#include <iostream>
using namespace std;
int modul(int a){
    if(a < 0){
        return -a;
    }
    return a;
}
int n, x1, x2;
int difmin = 2e9;
int difmin1, difmin2;
int main(){
    cin >> n;
    cin >> x2;
    for(int i = 2; i <= n; i++){
        cin >> x1;
        if(modul(x1-x2) < difmin){
            difmin = modul(x1-x2);
            difmin1 = x2;
            difmin2 = x1;
        }else if(modul(x1-x2) == difmin){
            if(x1+x2 < difmin1+difmin2){
                difmin1 = x2;
                difmin2 = x1;
            }
        }
        x2 = x1;
    }
    cout << difmin1 << ' ' << difmin2;
    return 0;
}
