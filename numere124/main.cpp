#include <iostream>
using namespace std;
int x, n;
int f[14];
void bt(int k, int nr){
    if(k == n+1){
        cout << nr << '\n';
    }else{
        for(int i = 0; i < 10; i++){
            if(i == 0 && k == 1) continue;
            if(f[i] == 0) continue;
            f[i]--;
            bt(k+1, nr*10+i);
            f[i]++;
        }
    }
}
int main(){
    cin >> x >> n;
    do{
        f[x%10]++;
        x = x/10;
    }while(x);
    bt(1, 0);
    return 0;
}
