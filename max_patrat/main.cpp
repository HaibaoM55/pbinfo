#include <iostream>
using namespace std;
int n, a[25][25];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    int j = n;
    for(int i = 1; i <= n; i++){
    	cout << max(a[i][j], a[i][i]) << '\n';
        j--;
    }
    return 0;
}
