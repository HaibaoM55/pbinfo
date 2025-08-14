#include <iostream>
using namespace std;
void consecutiv(int n, int &f){
    f = 1;
    while(f*(f-1) < n){
        f++;
    }
    f--;
}/*
int main(){
    int f;
    consecutiv(19, f);
    cout << f;
    return 0;
}
*/
