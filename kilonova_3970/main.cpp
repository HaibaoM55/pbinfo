#include <iostream>
#include <bitset>
using namespace std;
int n, m;
int v[3004],dp[3004], aux[3004];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = m; j >= v[i]; j--){
            dp[j] += dp[j-v[i]];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= m; j++){
            aux[j] = dp[j];
        }
        for(int j = v[i]; j <= m; j++){
            aux[j] -= aux[j-v[i]];
        }
        if(!aux[m]){
            cout << "YES";
        }else{
            cout << "NO";
        }
        cout << '\n';
    }
	return 0;
}
