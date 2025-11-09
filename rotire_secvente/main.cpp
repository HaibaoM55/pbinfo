#include <iostream>
using namespace std;
int n, k;
int v[1004];
int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    for(int i = 1; i <= n; i += n/k){
        for(int j = i+1; j < i+n/k; j++){
            cout << v[j] << ' ';
        }
        cout << v[i] << ' ';
    }
    return 0;
}
