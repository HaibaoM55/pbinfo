#include <iostream>
#include <algorithm>
using namespace std;
int n, vmin=2e9, vmax=0;
int x;
int main(){
	cin >> n;
    for(int i = 1; i <= n; i++){
    	cin >> x;
        vmin = min(vmin, x);
        vmax = max(vmax, x);
    }
    int g = __gcd(vmin, vmax);
    cout << vmin/g <<'/'<<vmax/g;
}
