#include <iostream>
using namespace std;
int n, v[1004];
int inloc(int x){
    int nr = 0;
    while(x > 9){
        nr++;
        x = x/10;
    }
    return (nr+1)*x;
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        v[i] = inloc(v[i]);
    }
    for(int i = 1; i <= n; i++){
        cout << v[i] << ' ';
    }
    return 0;
}
