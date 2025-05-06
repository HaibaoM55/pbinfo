#include <iostream>
using namespace std;
int n;
int main(){
    cin >> n;
    int f1 = 1, f2 = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == 1 && (j  == 1 || j == 2)){
                cout << "1 ";
            }else{
                cout << (f1+f2)%10 << ' ';
                int aux = f1;
                f1 = (f1+f2)%10;
                f2 = aux;
            }
        }
        cout << '\n';
    }
    return 0;
}
