#include <iostream>
using namespace std;
int n, x;
int v[400004];
bool f[400004];
int main(){
    long long s = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        f[v[i]] = true;
    }
    for(int i = 1; i <= 4e5; i++){
        for(int j = i; j <= 4e5; j += i){
            if((i+j)%2==0 && f[(j+i)/2] && f[(j-i)/2]){
                s++;
            }
        }
    }
    cout << s;
    return 0;
}
