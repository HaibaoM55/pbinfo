#include <iostream>
#include <algorithm>
using namespace std;
int n, k;
int v[200004];
int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
    	cin >> v[i];
    }
    sort(v+1, v+k+1);
    for(int i = 1; i <= k; i++){
    	cout << v[i] << ' ';
    }
    sort(v+k+1, v+n+1);
    for(int i = n; i >= k+1; i--){
    	cout << v[i] << ' ';
    }
	return 0;
}
