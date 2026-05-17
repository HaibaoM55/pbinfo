#include <iostream>
using namespace std;
int n;
long long s = 0;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
    	s += i*i;
    }
    cout << "Rezultatul este " << s;
	return 0;
}
