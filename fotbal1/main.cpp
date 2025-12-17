#include <iostream>
using namespace std;
int n, m;
unsigned long long a[2004][2004];
int main(){
    cin >> n >> m;
    for(int i = 0; i <= 2000; i++){
    	a[i][0] = 1;
        a[0][i] = 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
        	a[i][j] = a[i-1][j]+a[i][j-1];
        }
    }
    cout << (unsigned long long) a[n][m];
    return 0;
}
