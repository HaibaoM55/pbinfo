#include <iostream>
using namespace std;
int DouaNumere(int a[], int n){
    int f[90];
    for(int i = 0; i <= 81; i++){
        f[i] = 0;
    }
    int smax = -1;
    for(int i = 0; i < n; i++){
        int x = a[i], s = 0;
        do{
            s = s+x%10;
            x = x/10;
        }while(x > 0);
        if(f[s] != 0){
            smax = max(smax, f[s]+a[i]);
        }
        f[s] = max(f[s], a[i]);
    }
    return smax;
}/*
int main(){
    int v[67] = {14,66,41,50,93};
    cout << DouaNumere(v, 5);
    return 0;
}*/
