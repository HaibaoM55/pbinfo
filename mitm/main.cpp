#include <iostream>
#include <algorithm>
using namespace std;
int n, s;
int a[22];
int b[22];
long long val = 0;
long long vmax = 0;
void pc(int k){
    if(k == n+1){
        return;
    }else{
        for(int i = 1; i <= n; i++){
            p[k] = i;
            bool ok = true;
            for(int j = 1; j <= k-1; j++){
                if(p[j] == p[k]){
                    ok = false;
                    break;
                }
            }
            if(ok){
                val = 0;
                bool ok1 = true;
                for(int i = 1; i <= k; i++){
                    val += v[p[i]];
                    if(val > s){
                        ok1 = false;
                        break;
                    }
                }
                if(ok1){
                    vmax = max(val, vmax);
                    pc(k+1);
                }
            }
        }
    }
}
int main()
{
    cin >> n >> s;
    for(int i = 1; i <= n; i++){
        if(i < n/2){
            cin >> a[i];
        }else{
            cin >> b[n/2-i];
        }
    }
    pc(1);
    cout << vmax;
    return 0;
}
