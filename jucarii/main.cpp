#include <iostream>
using namespace std;
#define MOD 224737
int n, k;
long long rasp = 1;
int main(){
    cin >> k >> n;
    for(int i = n; i >= n-k+1; i--){
        rasp = 1LL*rasp*i;
        rasp = rasp%MOD;
    }
    cout << rasp;
	return 0;
}
