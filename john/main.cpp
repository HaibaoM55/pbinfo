#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
int n, m;
int maxim = 0;
int mx = 0;
int v[1005][1005];
int zi[1005];
int vc[1005];
unordered_map <int, int> f;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> vc[j];
        }
        sort(vc+1, vc+m+1);
        vc[0] = -1;
        int z = 0;
        for(int j = 1; j <= m; j++){
            if(vc[j] != vc[j-1]){
                z++;
                v[i][z] = vc[j];
                f[vc[j]]++;
                maxim = max(maxim, f[vc[j]]);
            }
        }
        zi[i] = z;
    }
    cout << maxim << '\n';
    for(int i = 1; i <= n-1; i++){
        for(int i1 = i+1; i1 <= n; i1++){
            int nr = 0;
            int p1 = 1, p2 = 1;
            while(p1 <= zi[i] && p2 <= zi[i1]){
                if(v[i][p1] > v[i1][p2]){
                    p2++;
                }else if(v[i][p1] < v[i1][p2]){
                    p1++;
                }else{
                    nr++;
                    p1++;
                    p2++;
                }
            }
            mx = max(mx, nr);
        }
    }
    cout << mx;
    return 0;
}
