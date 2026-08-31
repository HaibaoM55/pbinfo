#include <iostream>
using namespace std;
int n;
int nr = 0;
bool ciur[104];
int v[104];
void partitiiprime(int n, int k){
    if(n == 0){
        for(int i = 1; i <= v[0]; i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
    }
    v[0]++;
    for(int j = k; j <= n; j++){
        if(!ciur[j]){
            v[v[0]] = j;
            partitiiprime(n-j, j);
        }
    }
    v[0]--;
}
int main(){
    cin >> n;
    for(int i = 2; i <= n; i++){
        if(!ciur[i]){
            for(int j = i*i; j <= n; j+= i){
                ciur[j] = true;
            }
        }
    }
    partitiiprime(n, 2);
    return 0;
}
