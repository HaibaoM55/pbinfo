#include <iostream>
#include <vector>
using namespace std;
#pragma GCC optimize("O1")
int n, s;
int v[10], c[10];
vector<int> corect;
bool continua = true;
int f[10];
void bt(int i, int sm){
    if(sm > s){
    	return;
    }
    if(!continua){
    	return;
    }
    if(i == n+1){
        if(sm == s){
            for(int i = 0; i < n; i++){
            	cout << f[i] << ' ';
            }
            continua = false;
        }
        return;
    }
	f[i-1] = 0;
    bt(i+1, sm);
    for(int i1 = 1; i1 <= s; i1++){
        sm += v[i];
        if(sm > s){
        	return;
        }
        f[i-1] = i1;
        bt(i+1, sm);
    }
}
int main(){
    cin >> n >> s;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    bt(1, 0);
    return 0;
}
