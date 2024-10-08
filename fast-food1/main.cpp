#include <iostream>
using namespace std;
int n,vmax=0;
int v[10004];
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        v[x]++;
        v[y+1]--;
    }
    int nr = 0;
    for(int i = 1; i <= 10000; i++){
        v[i] = v[i-1]+v[i];
        vmax = max(vmax, v[i]);
    }
    cout << vmax;
    return 0;
}
