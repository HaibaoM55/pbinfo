#include <iostream>
using namespace std;
void F(int n, int a[], int &k){
    k = -1;
    for(int i = 0; i < n; i++){
        if(a[i] % 2 == 0){
            if(k == -1){
                k = a[i];
            }else{
                k = k*10+a[i];
            }
        }
    }
}/*
int main()
{
    int c[67] = {2, 3, 5, 6, 4, 1};//67 boi so tuff
    cout << F(6, c);
    return 0;
}*/
