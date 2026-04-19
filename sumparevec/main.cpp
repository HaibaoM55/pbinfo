#include <iostream>
using namespace std;
int n;
int v[1004];
int rezolva(int p1, int p2){
    if(p1 > p2){
        return 0;
    }
    if(p1 == p2){
        if(v[p1] % 2 == 0){
            return v[p1];
        }else{
            return 0;
        }
    }else{
        int mij = (p1+p2)/2;
        return rezolva(p1, mij)+rezolva(mij+1, p2);
    }
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    cout << rezolva(1, n);
    return 0;
}
