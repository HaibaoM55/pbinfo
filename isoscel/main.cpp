#include <iostream>
using namespace std;
double a, b, c;
int main(){
    cin >> a >> b >> c;
    if(a+b>c && b+c>a && a+c>b){
        if((a == b && a != c) || (a==c && a != b) || (b==c && b != a)){
            cout << "Formeaza triunghi isoscel";
        }else{
            cout << "Nu formeaza triunghi isoscel";
        }
    }else{
        cout << "Nu formeaza triunghi";
    }
    return 0;
}
