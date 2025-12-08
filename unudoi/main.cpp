#include <iostream>
using namespace std;
int rezolva(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    long long p = 1;
    while (p * 4 < n) {
        p *= 4;
    }
    long long q = (n - 1) / p;
    long long pos = (n - 1) % p + 1;
    int rez;
    if(q == 0) {
        rez = rezolva(pos);
    }else if(q == 1){
        rez = rezolva(pos);
        if(rez == 1){
        	rez = 2;
        }else{
        	rez = 1;
        }
    }else if(q == 2) {
        rez = rezolva(pos);
        if(rez == 1){
        	rez = 2;
        }else{
         	rez = 1;
        }
    }else{
        rez = rezolva(pos);
    }

    return rez;
}
int n;
int main(){
    cin >> n;
    cout << rezolva(n);
    return 0;
}
