#include <iostream>
using namespace std;
long long PerechiDivP(int a[], int n, int P){
    long long f[1004] = {0};
    for(int i = 0; i < n; i++){
        f[a[i]%P]++;
    }
    long long nr = (f[0]*(f[0]-1))/2;
    for(int i = 1; P-i > i; i++){
        nr += (f[P-i]*f[i]);
    }
    if(P % 2 == 0){
    	nr += (f[P/2]*(f[P/2]-1))/2;
    }
    return nr;
}/*
int main(){
    int a[67] = {1, 2, 3, 4, 5, 6};
    cout << PerechiDivP(a, 6, 3);
    return 0;
}
*/
