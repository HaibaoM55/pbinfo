#include <iostream>
#include <algorithm>
using namespace std;
int n;
int v[14], vmini = 0, vmin=2e9;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
    	cin >> v[i];
        if(v[i] < vmin){
        	vmin = v[i];
            vmini = i;
        }
    }
    sort(v+1, v+n+1);
    do{
        if(v[vmini] == vmin){
            for(int i = 1; i <= n; i++){
            	cout << v[i] << ' ';
            }
            cout << '\n';
        }
    }while(next_permutation(v+1, v+n+1));
	return 0;
}
