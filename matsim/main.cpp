#include <iostream>
using namespace std;
int n, a[104][104], b[104][104];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
        	cin >> a[i][j];
    		b[j][i] = a[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
        	cout << b[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
