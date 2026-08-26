#include <iostream>
using namespace std;
int n, v[1004];
int inloc(int x){
    int s = 0, vmax = 0;
    do{
        s += x%10;
        vmax = max(vmax, x%10);
        x = x/10;
    }while(x);
    return s*vmax;
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
