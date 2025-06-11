#include <iostream>
using namespace std;
long long x, suma = 0;
int main(){
    cin >> x;
    while(x > 9){
        suma = suma+(x%10);
        x = x/10;
    }
    if(x == suma){
        cout << "DA";
    }
    else{
        cout << "NU";
    }
    return 0;
}
