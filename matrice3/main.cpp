#include <iostream>
using namespace std;
int n, m;
int x;
int a[103][103];
int s[105];
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        s[i] = 0;
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            s[i] += a[i][j];
        }
    }
    int vmax = 0, vmaxi;
    for(int i = 1; i <= n; i++){
        int nr = 0;
        for(int j = 1; j <= n; j++){
            if(s[j] == s[i]){
                nr++;
            }
        }
        if(nr > vmax){
            vmax = nr;
            vmaxi = i;
        }
    }
    cout << n-vmax << '\n';
    for(int i = 1; i <= n; i++){
        //s[i]+x = s[vmaxi]
        //x = s[vmaxi]-s[i];
        if(s[i] != s[vmaxi]){
            int vmin=1000001, vmini;
            int vmax1=0, vmaxi1;
            for(int j = 1; j <= m; j++){
                if(a[i][j] > vmax1){
                    vmax1 = a[i][j];
                    vmaxi1 = j;
                }
                if(a[i][j] < vmin){
                    vmin = a[i][j];
                    vmini = j;
                }
            }
            if(s[i] > s[vmaxi]){
                a[i][vmaxi1] -= s[i]-s[vmaxi];
                cout << i << ' ' << vmaxi1 << ' '<<a[i][vmaxi1] << '\n';
            }else{
                a[i][vmini] += s[vmaxi]-s[i];
                cout << i << ' ' << vmini << ' '<<a[i][vmini] << '\n';
            }
        }
    }
    return 0;
}
