#include <fstream>
using namespace std;
ifstream cin("partitiinumar2.in");
ofstream cout("partitiinumar2.out");
int n, m;
int v[104];
void bt(int s){
    if(s == n){
        if(v[0] >= m){
            for(int i = 1; i <= v[0]; i++){
                cout << v[i] << ' ';
            }
            cout <<'\n';
        }
        return;
    }
    for(int i = v[v[0]]+1; s+i <= n; i++){
        v[0]++;
        v[v[0]] = i;
        bt(s+i);
        v[0]--;
    }
}
int main(){
    cin >> n >> m;
    bt(0);
    return 0;
}
