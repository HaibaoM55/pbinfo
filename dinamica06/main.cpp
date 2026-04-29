#include <iostream>
using namespace std;
#define MOD 123457
int n;
int put3(int x){
    if(x == 0){
        return 1;
    }
    if(x % 2 == 0){
        int r = put3(x/2);
        return (1LL*r*r)%MOD;
    }else{
        return (put3(x-1)*3)%MOD;
    }
}
int main(){
    cin >> n;
    cout << (put3(n-1)*2)%MOD;
    return 0;
}
