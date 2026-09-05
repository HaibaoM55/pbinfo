#include <fstream>
using namespace std;
ifstream cin("aranjamente.in");
ofstream cout("aranjamente.out");
int n, m, v[14];
bool b[14];
void bt(int k){
    if(k == m+1){
        for(int i = 1; i <= m; i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
    }else{
        for(int i = 1; i <= n; i++){
            if(!b[i]){
                b[i] = true;
                v[k] = i;
                bt(k+1);
                b[i] = false;
            }
        }
    }
}
int main(){
    cin >> n >> m;
    bt(1);
    return 0;
}
