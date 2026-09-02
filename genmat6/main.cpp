#include <iostream>
using namespace std;
int n, nrc=0;
int a[10][10];
int main(){
	cin >> n;
    int x = n;
    do{
        nrc++;
        n = n/10;
    }while(n);
    n = x;
    int i = 0;
    nrc++;
    do{
        i++;
        for(int j = i+1; j <= nrc; j++){
        	a[i][j] = n%10;
            a[j][i] = n%10;
        }
        n = n/10;
    }while(n);
    for(int i = 1; i <= nrc; i++){
        for(int j = 1; j <= nrc; j++){
        	cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
