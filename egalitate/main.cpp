#include <iostream>
using namespace std;
int Egalitate(int a[], int n){
    int f[1005];
    for(int i = 0; i <= 1000; i++){
        f[i] = 0;
    }
    for(int i = 0; i < n; i++){
        f[a[i]]++;
    }
    int nrmin = 10004;
    for(int i = 1; i <= 1000; i++){
        int nr = 0;
        for(int j = 0; j <= 1000; j++){
            if(f[j] < i){
                nr += f[j];
            }else{
                nr += f[j]-i;
            }
        }
        nrmin= min(nrmin, nr);
    }
    return nrmin;
}/*
int main(){
    int v[26] = {5,3,1,5,5,1,1,5};
    cout << Egalitate(v, 8);
    return 0;
}*/
