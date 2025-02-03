#include <iostream>
using namespace std;
int n;
int a[26][26];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            a[i][j] = 2;
        }
    }
    for(int i = 1; i <= n; i++){
        a[i][i] = 0;
    }
    int j = n;
    for(int i = 1; i <= n; i++){
        a[i][j] = 0;
        j--;
    }
    for(int j = 1; j <= (n-1)/2; j++){
        for(int i = j+1; i <= n-j; i++){
            a[i][j] = 3;
        }
    }
    for(int j = n; j > (n-1)/2; j--){
        for(int i = n-j+2; i <= j-1; i++){
            a[i][j] = 3;
        }
    }
    for(int i = 1;  i <= (n-1)/2; i++){
        for(int j = i+1; j <= n-i; j++){
            a[i][j] = 1;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
