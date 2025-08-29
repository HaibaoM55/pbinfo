#include <iostream>
using namespace std;
int n;
int a[100004], b[100004], c[100004];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }
    c[0] = -1;
    bool exista = true;
    for(int i = 1; i <= n; i++){
        // (E) x
        //a[i] <= x && x <= b[i]
        //x >= lst
        if(a[i] <= b[i] && c[i-1] <= b[i]){
            c[i] = max(a[i], c[i-1]);
        }else{
            exista = false;
            break;
        }
    }
    if(exista){
        for(int i = 1; i <= n; i++){
            cout << c[i] << ' ';
        }
    }else{
        cout << -1;
    }
    return 0;
}
