#include <iostream>
using namespace std;
long long NrSecvS(int a[], int n, int S){
    int j = 1;
    long long s = a[1], nrs = 0;
    a[0] = 0;
    for(int i = 1; i <= n; i++){
        s = s-a[i-1];
        for(int x = j+1; x <= n && s <= S; x++){
            if(s <= S){
                s += a[x];
                j = x;
            }
        }
        if(s > S){
            nrs += n-j+1;
        }
    }
    return nrs;
}/*
int main(){
    int a[104] = {0,3,6,3,1};
    cout << NrSecvS(a, 4, 10);
}*/
