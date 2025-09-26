#include <iostream>
using namespace std;
void prefix(int n, int k, int &x){
   	int v[67], z = 0;
    do{
        z++;
        v[z] = n%10;
    	n = n/10;
    }while(n > 0);
    x = 0;
    for(int i = z; i >= z-k+1; i--){
    	x=x*10+v[i];
    }
}/*
int main(){
    int x=0;
    prefix(27594, 3, x);
    cout << x;
    return 0;
}*/
