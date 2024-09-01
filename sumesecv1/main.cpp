#include <iostream>
using namespace std;
int n, m, nr;
long long s[100004];
long long vmax = 0;
int main()
{
    cin >> n;
    s[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> nr;
        s[i] = s[i-1]+nr;
    }
    cin >> m;
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        if(x < y){
            int aux = x;
            x = y;
            y = aux;
        }
        vmax = max(vmax, s[x]-s[y-1]);
    }
    cout << vmax;
    return 0;
}
