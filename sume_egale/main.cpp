#include <iostream>
#include <vector>
using namespace std;
int n, nr = 0;
int smaf = 0;
void bt(int kk, int suma){
    if(kk == n+1){
        return;
    }
    if(suma+kk < smaf){
        bt(kk+1, suma);
        bt(kk+1, suma+kk);
    }else if(suma+kk == smaf){
        nr++;
    }
}
vector<int> clearv;
int main(){
    cin >> n;
    smaf = n*(n+1);
    if(smaf % 4 != 0){
        cout << 0;
        return 0;
    }
    smaf = smaf/4;
    bt(1, 0);
    cout << nr/2;
    return 0;
}
