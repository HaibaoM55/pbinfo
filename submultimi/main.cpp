#include <fstream>
using namespace std;
ifstream cin("submultimi.in");
ofstream cout("submultimi.out");
int n;
int v[14];
bool ok = false;
void solve(){
    if(ok){
        for(int i = 1; i <= v[0]; i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
    }else{
        ok = true;
    }
    for(int i = v[v[0]]+1; i <= n; i++){
        v[0]++;
        v[v[0]] = i;
        solve();
        v[0]--;
    }
}
int main(){
    cin >> n;
    v[0] = 0;
    solve();
    return 0;
}
