#include <iostream>
using namespace std;
int n, m, x;
bool f[10004];
long long s = 0;
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> x;
            if(f[x] == false && x % 2 == 0){
                f[x] = true;
                s += x;
            }
        }
    }
    cout << s;
    return 0;
}
