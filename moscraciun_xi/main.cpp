#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int v[104];
int main(){
    cin >> m >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    sort(v+1, v+n+1);
    for(int i = n; i >= 1; i--){
        m -= v[i];
        if(m <= 0){
            cout << n-i+1;
            return 0;
        }
    }
    cout << "imposibil";
    return 0;
}
