#include <iostream>
using namespace std;
int n, t1, t2;
int v[10004];
int main()
{
    cin >> n >> t1 >> t2;
    for(int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        v[x]++;
        v[y]--;
    }
    int nr = 0;
    for(int i = t1; i <= t2-1; i++){
        v[i] = v[i-1]+v[i];
        if(v[i] == 0){
            nr++;
        }
    }
    cout << nr;
    return 0;
}
