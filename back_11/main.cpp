#include <iostream>
using namespace std;
int n;
bool b[14];
void bt(int k, int nr, int imp, int par){
    if(k == n+1){
        cout << nr << '\n';
    }else{
        for(int i = 0; i <= 9; i++){
            if(b[i]){
                continue;
            }
            if(i == 0 && k == 1){
                continue;
            }
            if(i % 2 == 1 && par+n-k <= imp+1){
                continue;
            }
            b[i] = true;
            bt(k+1, nr*10+i, imp+i%2, par+(i+1)%2);
            b[i] = false;
        }
    }
}
int main(){
    cin >> n;
    bt(1, 0, 0, 0);
    return 0;
}
