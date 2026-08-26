#include <iostream>
#include <algorithm>
using namespace std;
int n;
int v[1004];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
    	cin >> v[i];
    }
    int z = n;
    int s = 0;
    for(int i = 1; i < z; i++){
        if(__gcd(v[i], v[z]) == 1){
        	s += v[i];
            s += v[z];
        }
        z--;
    }
    cout << s;
	return 0;
}
