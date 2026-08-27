#include <iostream>
using namespace std;
long long n, x;
int main(){
	cin >> n;
    for(int i = 1; i <= n; i++){
    	cin >> x;
        cout << x%2 << ' ';
    }
    return 0;
}
