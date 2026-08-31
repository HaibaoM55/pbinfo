#include <iostream>
using namespace std;
int n, m;
int v[10];
bool esteprim(int k){
	return k == 2 || k == 3 || k == 5 || k == 7;
}
void bt(int k){
    if(k == n+1){
        for(int i = 1; i <= n; i++){
            cout << v[i];
        }
        cout << '\n';
        return;
    }
    for(int i = 0; i <= 9; i++){
     	if(!esteprim(i)){
            continue;
     	}
        v[k] = i;
    	bt(k+1);
    }
}
int main(){
    cin >> n;
    bt(1);
    return 0;
}
