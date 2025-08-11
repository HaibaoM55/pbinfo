#include <iostream>
using namespace std;
void sub(int n, int &a, int &b){
    a = n-1;
    for(a; a >= 2; a--){
        bool esteprim = true;
        for(int i = 2; i*i <= a; i++){
            if(a % i == 0){
                esteprim = false;
                break;
            }
        }
        if(esteprim){
            break;
        }
    }
    b = n+1;
    for(b; b <= 1000000000; b++){
        bool esteprim = true;
        for(int i = 2; i*i <= b; i++){
            if(b % i == 0){
                esteprim = false;
                break;
            }
        }
        if(esteprim){
            break;
        }
    }
}/*
int main(){
    int a, b;
    sub(28, a, b);
    cout << a << ' ' << b;
    return 0;
}
*/
