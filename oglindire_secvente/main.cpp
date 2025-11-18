#include <iostream>
using namespace std;
int n, k;
int v[1004];
int main(){
    cin >> n >> k;
    for(int i = 1; i <= n/k; i++){
        for(int j = 1; j <= k; j++){
            cin >> v[j];
        }
        int z = k;
        for(int j = 1; j <= z; j++){
            swap(v[j], v[z]);
            z--;
        }
        for(int j = 1; j <= k; j++){
            cout << v[j] << ' ';
        }
    }
}
