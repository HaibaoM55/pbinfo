#include <iostream>
using namespace std;
int n;
int nr = 0;
bool ciur[104];
int v[104];
void partitii(int n, int k){
    if(n == 0){
        for(int i = 1; i <= v[0]; i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
    }
    v[0]++;
    for(int j = k; j <= n; j++){
        if(v[0] == 1 || (j % 2 != v[v[0]-1]%2)){
            v[v[0]] = j;
            partitii(n-j, j);
        }
    }
    v[0]--;
}
int main(){
    cin >> n;
    partitii(n, 1);
    return 0;
}
