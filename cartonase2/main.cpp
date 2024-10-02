#include <iostream>
#include <algorithm>
using namespace std;
int n, p = 0, m;
int v[1004];
int vmin = 1000000000;
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n-m; i++){
        cin >> v[i];
    }
    int p = n-m+1;
    sort(v+1, v+p);
    int vmin = (v[n-m] - v[1]) / (n - 1);
    for(int j = 1; j <= n-m-1; j++){
        while(v[j]+vmin < v[j+1]){
            cout << v[j]+vmin << ' ';
            v[j] = v[j]+vmin;
            p++;
        }
    }
    for(int i = n-m+1; i <= n-p; i++){
        v[i] = v[i-1]+vmin;
        cout << v[i] << ' ';
    }
    return 0;
}
