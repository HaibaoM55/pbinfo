#include <iostream>
using namespace std;
int n, x;
bool f[1004];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> x;
            if(i > j && i+j <= n){
                f[x]=true;
            }
        }
    }
    for(int i = 0; i <= 1000; i++){
        if(f[i]){
            cout << i << ' ';
        }
    }
    return 0;
}
