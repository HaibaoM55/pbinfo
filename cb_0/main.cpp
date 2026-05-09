#include <iostream>
using namespace std;
int x, n;
int v[104];
int main(){
    cin >> x >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    int p1 = 1, p2 = n, p = n;
    while(p1 <= p2){
        int mij = (p1+p2)/2;
        if(v[mij] <= x){
            p1 = mij+1;
            p = mij;
        }else{
            p2 = mij-1;
        }
    }
    if(v[p] == x){
        cout << "Da " << p-1;
    }else{
        cout << "Nu exista";
    }
    return 0;
}
