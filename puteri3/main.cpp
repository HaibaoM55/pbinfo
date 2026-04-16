#include <iostream>
using namespace std;
int n;
int v[34];
int main(){
    cin >> n;
    int z = 0;
    int p = 1;
    if(n % 2 == 1){
        n--;
        cout << "1 ";
    }
    while(n){
        n = n/2;
        p = p*2;
        if(n % 2 == 1){
            cout << p << ' ';
        }
    }
    return 0;
}
