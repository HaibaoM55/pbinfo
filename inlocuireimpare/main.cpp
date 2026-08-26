#include <iostream>
using namespace std;
int n, v[1004];
int inloc(int x){
    if(x == 0){
        return 0;
    }
    int k = inloc(x/10);
    return (x%2==1)*x%10+k+(x%2==1)*9*k;
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        v[i] = inloc(v[i]);
    }
    for(int i = n; i >= 1; i--){
        cout << v[i] << ' ';
    }
    return 0;
}
