#include <iostream>
#include <unordered_map>
using namespace std;
int n, m, k;
int a[104][104];
int s[104];
unordered_map<int, int> f;
int vmax = 0, vmaxi = 0;
struct modificari{
    int i, j, val;
}mod[104];
int main(){
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            s[i] += a[i][j];
        }
        f[s[i]]++;
        if(f[s[i]] > f[vmax]){
            vmax = s[i];
        }
    }
    int p = 0;
    for(int i = 1; i <= n; i++){
        if(s[i] != vmax){
            int vmax1 = 0, vmaxi=0;
            if(vmax-s[i] < 0){
                for(int j = 1; j <= m; j++){
                    if(a[i][j] > vmax1){
                        vmax1 = a[i][j];
                        vmaxi = j;
                    }
                }
                p++;
                mod[p].i = i;
                mod[p].j = vmaxi;
                mod[p].val = vmax-s[i]+a[i][vmaxi];
                if(vmax-s[i]+a[i][vmaxi] < 0){
                    vmax1 = 0;
                    mod[p].val = 0;
                    int vmaxi1 = 0;
                    for(int j = 1; j <= m; j++){
                        if(a[i][j] > vmax1 && j != vmaxi){
                            vmaxi1 = i;
                            vmax1 = a[i][j];
                        }
                    }
                    p++;
                    mod[p].i = i;
                    mod[p].j = vmaxi1;
                    mod[p].val = vmax-s[i]+a[i][vmaxi]+a[i][vmaxi1];
                }
            }else{
                p++;
                mod[p].i = i;
                mod[p].j = 1;
                mod[p].val = vmax-s[i]+a[i][1];
            }
        }
    }
    cout << p << '\n';
    for(int i = 1; i <= p; i++){
        cout << mod[i].i << ' ' << mod[i].j << ' ' << mod[i].val << '\n';
    }
    return 0;
}
