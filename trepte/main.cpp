#include <iostream>
using namespace std;
long long f[34];
int n;
int main()
{
    f[1] = 1;
    f[2] = 2;
    cin >> n;
    for(int i = 3; i <= n; i++){
        f[i] = f[i-1]+f[i-2];
    }
    cout << f[n];
    return 0;
}
