#include <iostream>
using namespace std;
int n, k;
int v[1004];
int main(){
	cin >> n >> k;
    for(int i = 1; i <= n; i++){
    	cin >> v[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n-k+1; j++){
            bool ok = true;
            for(int z = 0; z < k; z++){
                if(v[i+z] != v[j+z]){
                	ok = false;
                    break;
                }
            }
            if(ok){
            	cout << i << ' ' << j;
                return 0;
            }
        }
    }
    cout << "NU";
    return 0;
}
