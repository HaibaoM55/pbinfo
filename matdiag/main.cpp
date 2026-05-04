#include <iostream>
using namespace std;
int a[100][100], n;
int MatDiag(int a[100][100], int n){
   for(int i = 0; i < n; i++){
      for(int k = 0; i+k < n; k++){
            if(a[i+k][k] != a[i][0] || a[k][i+k] != a[0][i]){
                return 0;
            }
        }
    }
   return 1;
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    cout << MatDiag(a, n);
    return 0;
}
