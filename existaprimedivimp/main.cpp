#include <iostream>
using namespace std;
bool esteprim(int x){
    for(int i = 2; i * i <= x; i++){
        if(x % i==0){
         	return false;
        }
    }
    return true;
}
bool obamahavdih(int v[1004], int st, int dr){
    int mij = (st+dr)/2;
    if(st == dr){
        if(esteprim(v[st])){
            return true;
        }else{
        	return false;
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
