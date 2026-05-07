#include <iostream>
using namespace std;
int n;
bool estepalindrom(int x){
    int v[67];
    v[0] = 0;
    do{
        v[0]++;
        v[v[0]] = x%10;
        x = x/10;
    }while(x);
    int z = v[0];
    for(int i = 1; i <= z; i++){
        if(v[i] != v[z]){
            return false;
        }
        z--;
    }
    return true;
}
int x;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x;
        if(!estepalindrom(x)){
            cout << x << ' ';
        }
    }
    return 0;
}
