#include <iostream>
using namespace std;
int n, x, y;
bool viz[104];
bool f[104][104];
int v[104];
void visit(int k, int p){
    v[p] = k;
    viz[k] = true;
    if(p == n){
        for(int i = 1; i <= n; i++){
            cout << v[i] << ' ';
        }
        exit(0);
    }else{
        for(int i = 1; i <= n; i++){
            if(!viz[i] && f[k][i]){
                visit(i, p+1);
            }
        }
    }
}
int main(){
    cin >> n;
    for(int i = 1; i <= (n*(n-1)/2); i++){
        cin >> x >> y;
        f[x][y] = true;
    }
//    for(int i = 1; i <= n; i++){
//        v[0] = 0;
//        for(int j = 1; j <= n; j++){
//            viz[j]
//        }
//        visit(i);
//        if(v[0] == n){
//            for(int j = 1; j <= n; j++){
//                cout << v[j] << ' ';
//            }
//            return 0;
//        }
//    }
    for(int i = 1; i <= n; i++){
        visit(i, 1);
        viz[i] = false;
    }
    return 0;
}
