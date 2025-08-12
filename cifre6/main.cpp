#include <iostream>
using namespace std;
void numar(int n, int k, int &x){
    int f[12] = {0,0,0,0,0,0,0,0,0,0};
    do{
        f[n%10]++;
        n = n/10;
    }while(n > 0);
    x=0;
    while(k > 0){
        for(int i = 9; i >= 0; i--){
            if(f[i]){
                x = x*10+i;
                f[i]--;
                k--;
                break;
            }
        }
    }
}/*
int main(){
    int x;
    numar(27594 , 3 , x);
    cout << x;
    return 0;
}
*/
