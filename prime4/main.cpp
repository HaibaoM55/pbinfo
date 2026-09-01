#include <fstream>
using namespace std;
ifstream cin("prime4.in");
ofstream cout("prime4.out");
int n, vmax = 0, vmaxi=0;
int v[10004];
int f[10004];
bool esteprim(int k){
    if(k < 2) return false;
    for(int i = 2; i*i <= k; i++){
    	if(k % i == 0) return false;
    }
    return true;
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
    	cin >> v[i];
        f[v[i]]++;
        if(esteprim(v[i])){
            if(f[v[i]] > vmax || (v[i] < vmaxi && f[v[i]] == vmax)){
            	vmax = f[v[i]];
                vmaxi = v[i];
            }
        }
    }
    cout << vmaxi;
    return 0;
}
