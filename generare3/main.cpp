#include <iostream>
using namespace std;
int n;
int x[14];
void cp(){
    x[1]++;
    for(int i = 1; i <= n; i++){
        if(x[i] == 2){
            x[i]=0;
            x[i+1]++;
        }
    }
    if(x[n+1] != 1){
        for(int i = n; i >= 1; i--){
            cout << x[i];
        }
        cout << '\n';
        cp();
    }
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        x[i] = 0;
        cout << 0;
    }
    cout << '\n';
    cp();
    return 0;
}
