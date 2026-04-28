#include <iostream>
using namespace std;
int n;
int v[304];
void bt(int x, int y, int poz){
    if(x < 0){
        return;
    }
    if(x == 0){
        for(int i = 1; i < poz; i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = y+1; i <= y+2; i++){
        v[poz] = i;
        bt(x-i, i, poz+1);
    }
}
int main(){
    cin >> n;
    for(int i = 0; i <= n; i += 2){
        bt(n, i, 1);
    }
    return 0;
}
