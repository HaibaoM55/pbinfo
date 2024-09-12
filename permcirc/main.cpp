#include <iostream>
using namespace std;
int n;
int v[1005];
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        cout << v[i] << ' ';
    }
    cout << '\n';
    for(int j = 1; j <= n-1; j++){
        v[n+1] = v[1];
        for(int i = 2; i <= n; i++){
            v[i-1] = v[i];
            cout << v[i] << ' ';
        }
        v[n] = v[n+1];
        cout << v[n] << '\n';
    }
    return 0;
}
