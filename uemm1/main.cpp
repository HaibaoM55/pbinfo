#include <iostream>
using namespace std;
int n;
int v[100004];
int stiva[100004];
int dr=0;
int f[100004];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    for(int i = 1; i <= n; i++){
        while(v[stiva[dr]] < v[i] && dr > 0){
            f[stiva[dr]] = i;
            dr--;
        }
        dr++;
        stiva[dr] = i;
    }
    for(int i = 1; i <= n; i++){
        if(f[i] == 0){
            cout << "-1 ";
        }else{
            cout << v[f[i]] << ' ';
        }
    }
    return 0;
}
