#include <iostream>
using namespace std;
int n, m;
int v[104];
int x;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    cin >> m;
    int pretmin = 2e9;
    for(int j = 1; j <= m; j++){
        int pret = 0;
        for(int i = 1; i <= n; i++){
            cin >> x;
            if(x == -1){
                pret = 1e9;
            }else{
                pret += x*v[i];
            }
        }
        pretmin = min(pretmin, pret);
    }
    cout << pretmin;
    return 0;
}
