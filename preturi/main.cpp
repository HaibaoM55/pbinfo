#include <iostream>
using namespace std;
int n, m, x;
int c[104];
int minim[104];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> c[i];
    }
    cin >> m;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cin >> x;
            if(x == -1){
                continue;
            }
            if(minim[j] == 0){
                minim[j] = x;
            }else{
                if(minim[j] > x){
                    minim[j] = x;
                }
            }
        }
    }
    long long s = 0;
    for(int i = 1; i <= n; i++){
        s = s + 1LL*minim[i]*c[i];
    }
    cout << s;
    return 0;
}
