#include <iostream>
#include <algorithm>
using namespace std;
int n, m, a[26][26];
int main(){
    cin >> n;
    m = n;
    int z = 2;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << z << ' ';
            z += 2;
            if(z % 3 == 0){
            	z += 2;
            }
        }
        cout << '\n';
    }
}
