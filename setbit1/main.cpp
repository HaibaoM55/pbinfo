#include <iostream>
using namespace std;
long long n, x;
int main(){
	cin >> n >> x;
    n = n | (1LL << x);
    cout << n;
    return 0;
}
