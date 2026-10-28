#include <iostream>
using namespace std;
int n;
int f[25];
int main(){
    cin >> n;
    f[1] = 1;
    for(int i = 2; i <= n; i++){
        f[i] = 2*f[i-1]+1;
    }
    cout << f[n];
}
