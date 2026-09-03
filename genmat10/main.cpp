#include <iostream>
#include <algorithm>
using namespace std;
int n, m, a[26][26];
int main(){
	cin >> n >> m;
    int z = n*m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
        	cout << z << ' ';
        	z--;
        }
        cout << '\n';
    }
}
