#include <iostream>
using namespace std;
int n, x;
int a[104][104];
long long s1[104];
long long s2[104];
int main(){
    cin >> n;
    int nr = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            s1[i] += a[i][j];
            s2[j] += a[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(s1[i] == s2[j]){
                nr++;
            }
        }
    }
    cout << nr;
    return 0;
}
