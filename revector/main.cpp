#include <iostream>
using namespace std;
int n, x;
int v[100004];
int f[100004];
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    x = n;
    int z = 0;
    for(int i = 1; i <= n/2; i++){
        z++;
        f[z] = i;
        z++;
        f[z] = n-i+1;
    }
    if(z == n-1){
        z++;
        f[z] = (n/2)+1;
    }
    for(int i = n; i >= 1; i--){
        cout << v[f[i]] << ' ';
    }
    return 0;
}
