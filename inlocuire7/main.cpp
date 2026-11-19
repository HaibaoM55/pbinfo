#include <iostream>
#include <algorithm>
using namespace std;
int n, x;
int v[1004];
int oglindit(int k){
    int nrc = 0;
    int nro = k;
    int c[104];
    do{
        nrc++;
        c[nrc] = k%10;
        k = k/10;
    }while(k);
    reverse(c+1, c+nrc+1);
    if(nrc % 2 == 1){
        return nro;
    }
    int z = nrc/2+1;
    for(int i = 1; i <= nrc/2; i++){
        swap(c[i], c[z]);
        z++;
    }
    int p = 0;
    for(int i = 1; i <= nrc; i++){
        p = p*10+c[i];
    }
    return p;
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x;
        int og = oglindit(x);
        if(og != -1){
            v[0]++;
            v[v[0]] = og;
        }
    }
    sort(v+1, v+v[0]+1);
    for(int i = v[0]; i >= 1; i--){
        cout << v[i] << ' ';
    }
    return 0;
}
