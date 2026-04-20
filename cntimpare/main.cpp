#include <iostream>
using namespace std;
int n;
int v[1004];
int cntImpare(int p1, int p2){
    if(p1 > p2){
        return 0;
    }
    if(p1 == p2){
        return v[p1]%2;
    }else{
        int mij = (p1+p2)/2;
        return cntImpare(p1, mij)+cntImpare(mij+1, p2);
    }
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    cout << cntImpare(1, n);
}
