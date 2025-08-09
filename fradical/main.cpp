#include <iostream>
#include <math.h>
using namespace std;
void FRadical(int n, int &x, int &y){
    int sq = sqrt(n);
    for(int i = sq; i >= 1; i--){
        int q = i*i;
        if(n % q == 0){
            x = i;
            y = n/q;
            return;
        }
    }
}/*
int main(){
    int x, y;
    FRadical(15000, x, y);
    cout << x << ' ' << y;
    return 0;
}
*/
