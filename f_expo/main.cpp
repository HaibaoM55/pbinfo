#include <iostream>
using namespace std;
void f_expo(int a[], int n){
    int f[25];
    f[0] = 1;
    for(int i = 1; i <= 20; i++){
        f[i] = f[i-1]*2;
    }
    for(int i = 0; i < n; i++){
        int p1 = 0, p2 = 20, p = 0;
        while(p1 <= p2){
            int mij = (p1+p2)/2;
            if(f[mij] <= a[i]){
                p = mij;
                p1 = mij+1;
            }else{
                p2 = mij-1;
            }
        }
        a[i] = p;
    }
}/*
int main(){
    int v[67] = {9,1,5,15,19,30};
    f_expo(v, 6);
}*/
