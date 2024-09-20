#include <iostream>
#include <algorithm>
using namespace std;
int n, p = 0;
int v[1004];
int vmin = 1000000000;
int main()
{
    cin >> n;
    for(int i = 1; i <= n-2; i++){
        cin >> v[i];
    }
    sort(v+1, v+n-1);
    vmin = (v[n - 2]- v[1]) / (n - 1);
    for(int j = 1; j <= n-3; j++){
        while(v[j]+vmin < v[j+1]){
            cout << v[j]+vmin << ' ';
            v[j] = v[j]+vmin;
            p++;
        }
    }
    if(p == 0){
        cout << v[n-2]+vmin << " " << v[n-2]+2*vmin;
    }else if(p == 1){
        cout << v[n-2]+vmin;
    }
    return 0;
}
