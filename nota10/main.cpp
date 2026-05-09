#include <iostream>
using namespace std;
int n, x,vmax,nr = 0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> n;
    vmax = -2e9;
    for(int i = 1; i <= n; i++){
    	cin >> x;
        if(x > vmax){
            vmax = x;
        	nr++;
        }
    }
    cout << nr;
}
