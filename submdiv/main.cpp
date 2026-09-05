#include <fstream>
#include <algorithm>
using namespace std;
ifstream cin("submdiv.in");
ofstream cout("submdiv.out");
int x, n;
bool exista = false;
int v[10], r[1004];
void bt(int k, int vmax){
    if(k == n+1){
        exista = true;
        for(int i = 1; i <= n; i++){
            cout << r[v[i]] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = vmax+1; i <= r[0]; i++){
        v[k] = i;
        bt(k+1, i);
    }
}
int main(){
    cin >> x >> n;
    for(int i = 1; i*i <= x; i++){
        if(x % i == 0){
            r[0]++;
            r[r[0]] = i;
            if(i*i < x){
                r[0]++;
                r[r[0]] = x/i;
            }
        }
    }
    sort(r+1, r+r[0]+1);
    bt(1, 0);
    if(!exista){
    	cout << "fara solutie";
    }
    return 0;
}
