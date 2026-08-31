#include <iostream>
using namespace std;
int n, x, y;
int v[10];
void bt(int k){
    if(k == n+1){
        for(int i = 1; i <= n; i++){
            cout << v[i];
        }
        cout << '\n';
        return;
    }
    for(int i = x; i <= y; i++){
     	v[k] = i;
    	bt(k+1);
    }
}
int main(){
    cin >> x >> y >> n;
    bt(1);
}
