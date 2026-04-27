#include <iostream>
using namespace std;
int n;
bool v[14][14];
bool verif(){
    int nr = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(v[i][j]){
                for(int i1 = i-1, j1 = j-1; i1 >= 1 && j1 >= 1; i1--, j1--){
                    if(v[i1][j1]){
                        return false;
                    }
                }
                for(int i1 = i-1; i1 >= 1; i1--){
                    if(v[i1][j]){
                        return false;
                    }
                }
                for(int i1 = i+1; i1 <= n; i1++){
                    if(v[i1][j]){
                        return false;
                    }
                }
                for(int i1=i+1, j1=j+1; i1 <= n && j1 <= n; i1++, j1++){
                    if(v[i1][j1]){
                        return false;
                    }
                }
                for(int i1=i+1, j1=j-1; i1 <= n && j1 >= 1; i1++, j1--){
                    if(v[i1][j1]){
                        return false;
                    }
                }
                for(int j1 = j-1; j1 >= 1; j1--){
                    if(v[i][j1]){
                        return false;
                    }
                }
                for(int j1 = j+1; j1 <= n; j1++){
                    if(v[i][j1]){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
bool a[14][14];
bool continua = true;
void bt(int x){
    if(!continua){
        return;
    }
    if(x == n+1){
        if(verif()){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    a[i][j] = v[i][j];
                }
            }
            continua = false;
        }
    }
    if(x == n+1){
        return;
    }
    for(int i = 1; i <= n; i++){
        bool ok = true;
        for(int j = 1; j <= x-1; j++){
            if(v[j][i]){
                ok = false;
                break;
            }
        }
        if(ok){
            v[x][i] = true;
            bt(x+1);
            v[x][i] = false;
        }
    }
}
int main(){
    cin >> n;
    bt(1);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(a[i][j]){
                cout << '*';
            }else{
                cout << '-';
            }
            cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}
