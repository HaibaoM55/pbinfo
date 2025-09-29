#include <iostream>
using namespace std;
int obamahavdih(int v[1004], int st, int dr){
    int mij = (st+dr)/2;
    if(st == dr){
        return v[st];
    }else{
        return obamahavdih(v, st, mij)+obamahavdih(v, mij+1, dr);
    }
}
int n, v[1004];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    cout << obamahavdih(v, 1, n);
    return 0;
}
