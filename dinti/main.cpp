#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n;
void dinte(int x){
    if(x == 1){
        cout << "1 ";
    }else{
        dinte(x-1);
        cout << x << ' ';
        dinte(x-1);
    }
}
int main(){
    cin >> n;
    dinte(n);
    return 0;
}
