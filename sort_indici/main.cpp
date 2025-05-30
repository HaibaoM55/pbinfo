#include <iostream>
#include <algorithm>
using namespace std;
int n;
struct vectorficios{
    int val, ind;
}v[104];
bool compara(vectorficios a, vectorficios b){
    if(a.val == b.val){
        return a.ind < b.ind;
    }
    return a.val < b.val;
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i].val;
        v[i].ind = i;
    }
    sort(v+1, v+n+1, compara);
    for(int i = 1; i <= n; i++){
        cout << v[i].val << ' ' << v[i].ind << ' ';
    }
    return 0;
}
