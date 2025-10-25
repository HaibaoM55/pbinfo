#include <iostream>
using namespace std;
int a,b;
int main(){
    cin >> a >> b;
    cout << a+b-1;
    cout << '\n';
    if(a == b){
        if(a % 2 != 0){
            cout << "mar";
        }else{
            cout << "para";
        }
    }else{
        if(a < b){
            cout << "mar";
        }else{
            cout << "para";
        }
    }
}
