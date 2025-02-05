#include <iostream>
#include <algorithm>
using namespace std;
int n, z = 0;
int v[1004], a[1004];
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    for(int i = 1; i < n; i++){
        int x = __gcd(v[i], v[n]);
        if(x == 1){
            z++;
            a[z] = v[i];
        }
    }
    sort(a+1, a+z+1);
    for(int i = z; i >= 1; i--){
        cout << a[i] << ' ';
    }
    return 0;
}
