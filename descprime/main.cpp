#include <iostream>
using namespace std;
int n, sma = 0;
int d[104],v[104], rf[104];
bool esteprim(int k){
    if(k < 2) return false;
    for(int i = 2; i*i <= k; i++){
    	if(k % i == 0) return false;
    }
    return true;
}
int bt(int k, int vmax){
    if(k == 0){
        if(rf[0] == 0){
            for(int i = 0; i <= v[0]; i++){
                rf[i] = v[i];
            }
        }
        return 1;
    }
    if(d[k] != 0) return d[k];
    int s = 0;
    for(int i = vmax+1; i <= k; i++){
        if(esteprim(i)){
            v[0]++;
            v[v[0]] = i;
        	s += bt(k-i, i);
            v[0]--;
        }
    }
    return s;
}
int main(){
    cin >> n;
	cout << bt(n, 1) << '\n';
	for(int i = 1; i <= rf[0]; i++){
        cout << rf[i] << ' ';
	}
    return 0;
}
