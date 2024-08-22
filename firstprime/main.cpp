#include <bits/stdc++.h>
using namespace std;
int n, x;
long long s = 0;
int fp[100000000];
int main()
{
    int k;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (k = 3; k*k <= 100000000; k += 2){
        if(!fp[k]){
            for(int j = k*k; j <= 100000000; j += k<<1){
                if (!fp[j]){
                    fp[j] = k;
                }
            }
        }
    }
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x;
        if(x <= 1){
            continue;
        }
        if(x % 2 == 0){
            s += 2;
        }else if(!fp[x]){
            s += x;
        }else{
            s += fp[x];
        }
    }
    cout << s;
    return 0;
}
