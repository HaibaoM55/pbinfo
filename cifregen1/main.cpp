#include <iostream>
using namespace std;
int n, m;
int v[10];
void bt(int k){
    if(k == n+1){
        for(int i = 1; i <= n; i++){
            cout << v[i];
        }
        cout << '\n';
        return;
    }
    for(int i = 0; i < m; i++){
     	if(i == 0 && k == 1){
            continue;
     	}
        v[k] = i;
    	bt(k+1);
    }
}
int main(){
    cin >> n >> m;
    bt(1);
    return 0;
}
