#include <iostream>
using namespace std;
int n, m, k;
int s[1001][1001];
int main()
{
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int x;
            cin >> x;
            s[i][j] = s[i-1][j]+s[i][j-1]-s[i-1][j-1]+x;
        }
    }
    int vmax = 0;
    for(int i = 1; i <= k; i++){
        int is, js, ij, jj;
        cin >> is >> js >> ij >> jj;
        vmax = max(vmax, s[ij][jj]-s[is-1][jj]-s[ij][js-1]+s[is-1][js-1]);
    }
    cout << vmax;
    return 0;
}
