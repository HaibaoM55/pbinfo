#include <iostream>
using namespace std;
int n, a[25][25];
int modul(int x){
	if(x < 0) return -x;
    return x;
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
        	cin >> a[i][j];
        }
    }
    int s1 = 0;
    for(int i = 1; i <= n; i++){
    	s1 += a[i][i];
    }
    int s2 = 0;
    int j = n;
    for(int i = 1; i <= n; i++){
    	s2 += a[i][j];
        j--;
    }
    cout << modul(s1-s2);
	return 0;
}
