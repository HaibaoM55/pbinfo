#include <fstream>
using namespace std;
ifstream cin("combinari1n.in");
ofstream cout("combinari1n.out");
int n, k;
int v[24];
void bt(int vmax){
    if(v[0] == k-2){
        cout << 1 << ' ';
        for(int i = 1; i <= k-2; i++){
            cout << v[i] << ' ';
        }
        cout << n << '\n';
        return;
    }
    for(int j = vmax+1; j < n; j++){
        v[0]++;
        v[v[0]] = j;
        bt(j);
        v[0]--;
    }
}
int main(){
    cin >> n >> k;
    bt(1);
    return 0;
}
