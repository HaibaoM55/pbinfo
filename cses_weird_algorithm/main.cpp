#include <iostream>
using namespace std;
long long n;
void urm(long long x){
    cout << x << ' ';
    if(x == 1){
        return;
    }
    if(x % 2 == 0){
        urm(x/2);
    }else{
        urm(x*3LL+1);
    }
}
int main(){
    cin >> n;
    urm(n);
    return 0;
}
