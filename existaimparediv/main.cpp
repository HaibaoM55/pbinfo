#include <iostream>
using namespace std;
bool obamahavdih(int v[1004], int st, int dr){
    int mij = (st+dr)/2;
    if(st == dr){
        if(v[st] % 2 == 1){
            return true;
        }
    }else{
        return obamahavdih(v, st, mij) || obamahavdih(v, mij+1, dr);
    }
}
int n, v[1004];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    if(obamahavdih(v, 1, n)){
        cout << "DA";
    }else{
        cout << "NU";
    }
    return 0;
}
