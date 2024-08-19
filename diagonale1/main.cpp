#include <iostream>
using namespace std;
int n;
int a[101][101];
long long s = 0;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 2; i <= n; i++){
        s = s + a[i][i-1];
    }
    for(int i = 2; i <= n; i++){
        s = s + a[i-1][i];
    }
    cout << s;
    return 0;
}
