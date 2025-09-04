#include <iostream>
using namespace std;
int a, b;
int n = 0;
int vc[10], v[10];
void kp(int k){
    if(k == n+1){
        for(int i = 1; i <= n; i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
    }else{
        for(int i = 1; i <= n; i++){
            bool ok = true;
            for(int j = 1; j <= k-1; j++){
                if(vc[i] == v[j]){
                    ok = false;
                    break;
                }
            }
            if(ok){
                v[k] = vc[i];
                kp(k+1);
            }
        }
    }
}
int main(){
    cin >> a >> b;
    n = b-a+1;
    for(int i = a; i <= b; i++){
        vc[i-a+1] = i;
    }
    kp(1);
    return 0;
}
