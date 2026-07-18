#include <fstream>
using namespace std;
ifstream cin("mex.in");
ofstream cout("mex.out");
int n, k, x;
int f[100004];
int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> x;
        f[x]++;
    }
    int nr = 0;
    for(int i = 1; i <= k; i++){
        if(!f[i]){
            nr++;
        }
    }
    cout << max(nr, f[k]);
    return 0;
}
