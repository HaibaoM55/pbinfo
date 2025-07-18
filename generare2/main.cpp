#include <iostream>
using namespace std;
int n, a, x, y;
bool f[10004];
void generare(int nr){
    if(f[nr] == false){
        f[nr] = true;
        if(nr+x <= n){
            generare(nr+x);
        }
        if(nr+y <= n){
            generare(nr+y);
        }
    }
}
int main(){
    cin >> n >> a  >> x >> y;
    generare(a);
    for(int i = 0; i <= n; i++){
        if(f[i]){
            cout << i << ' ';
        }
    }
    return 0;
}
