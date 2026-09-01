#include <iostream>
using namespace std;
int n, m;
int v[1004], a[1004];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
    	cin >> v[i];
    }
    cin >> m;
    for(int i = 1; i <= m; i++){
    	cin >> a[i];
    }
    int rez = 0;
    for(int i = 1; i <= n-m+1; i++){
        int ok = 1;
        for(int j = i; j <= i+m-1; j++){
            if(v[j] != a[j-i+1]){
				ok = 0;
                break;
            }
        }
        rez += ok;
    }
    cout << rez;
	return 0;
}
