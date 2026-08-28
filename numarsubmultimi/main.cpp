#include <iostream>
using namespace std;
int n, k;
long long rasp = 1;
int main(){
    cin >> n >> k;
    for(int i = k+1; i <= n; i++){
        rasp = 1LL*rasp*i;
    }
    for(int i = 1; i <= n-k; i++){
        rasp = rasp/i;
    }
    cout << rasp;
    return 0;
}
