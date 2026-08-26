#include <iostream>
using namespace std;
int n;
long long fierastrau(int x){
    if(x == 1) return 1;
	return x+2LL*fierastrau(x-1);
}
int main(){
	cin >> n;
    long long r = fierastrau(n);
    cout << r;
    return 0;
}
