#include <iostream>
using namespace std;
int n, k;
long long c = 0;
int v[100004];
int f[100004];
int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    v[0] = 0;
    f[v[0]]++;
    int p = 0;
    int ka = 1;
    for(int i = 1; i <= n-k+1; i++){
        f[v[i-1]]--;
        if(f[v[i-1]] == 0){
            ka--;
        }
        while(ka < k && p < n){
            p++;
            f[v[p]]++;
            if(f[v[p]] == 1){
                ka++;
            }
        }
        if(ka >= k){
            c = c+n-p+1;
        }else{
            break;
        }
    }
    cout << c;
    return 0;
}
