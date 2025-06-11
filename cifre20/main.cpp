#include <iostream>
using namespace std;
int n,x,nr;
int main() {
    cin>>n;
    for(int i = 1; i <= n; i++){
        int nrcif = 0;
        cin >> x;
        do{
            nrcif++;
            x = x/10;
        }while(x > 0);
        if(nrcif % 2 == 1){
            nr++;
        }
    }
    cout<<nr;

}
