#include <iostream>
using namespace std;
#define MOD 1000000007
int q;
int m, k;
int put(int x, int y){
    if(y == 0){
        return 1;
    }else{
        if(y % 2 == 0){
            long long pp = put(x, y/2);
            return (pp*pp)%MOD;
        }else{
            return (put(x,y-1)*y)%MOD;
        }
    }
}
int rasp(int x, int y){
    int nrc = (x+1)/2;
    return put(y, nrc);
}
int main(){
    cin >> q;
    for(int bosu = 1; bosu <= q; bosu++){
        cin >> m >> k;
        cout << rasp(m, k) << '\n';
    }
    return 0;
}
