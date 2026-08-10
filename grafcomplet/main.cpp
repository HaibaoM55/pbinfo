#include <iostream>
using namespace std;
int n, k;
int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i % k != j % k){
                cout << 1;
            }else{
                cout << 0;
            }
            cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}
