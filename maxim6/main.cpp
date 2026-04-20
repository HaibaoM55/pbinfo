#include <iostream>
using namespace std;
int m,n;
int v[1004];
int rasp(int p1, int p2){
    if(p1 > p2){
        return 0;
    }
    if(p1 == p2){
        return v[p1];
    }else{
        int mij = (p1+p2)/2;
        return max(rasp(p1, mij),rasp(mij+1, p2));
    }
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    cout << rasp(1, n);
    return 0;
}
