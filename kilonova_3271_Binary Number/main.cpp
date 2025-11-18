#include <iostream>
using namespace std;
int n;
int r[1000004];
int main(){
    cin >> n;
    if(n == 1){
        cout << 1;
        return 0;
    }
    r[0] = 0;
    for(int i = 1; i <= n; i++){
        r[i] = r[i-1]*10+1;
        r[i] = r[i]%n;
    }
    for(int i = 1; i <= n; i++){
        if(r[i] == r[n]){
            for(int j = n; j > i; j--){
                cout << 1;
            }
            for(int j = i; j >= 1; j--){
                cout << 0;
            }
            return 0;
        }
    }
    return 0;
}
