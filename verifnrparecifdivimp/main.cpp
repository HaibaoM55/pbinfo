#include <iostream>
using namespace std;
int n;
int v[104];
int nrcifre(int x){
    int nr = 0;
    do{
        nr++;
        x = x/10;
    }while(x > 0);
    return nr;
}
bool verif(int p1, int p2){
    int mij = (p1+p2)/2;
    if(p1 == p2){
        return (nrcifre(v[mij]) % 2 == 0);
    }else{
        return verif(p1, mij) && verif(mij+1, p2);
    }
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    if(verif(1, n)){
        cout << "DA";
    }else{
        cout << "NU";
    }
    return 0;
}
