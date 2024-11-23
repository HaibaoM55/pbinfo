#include <iostream>
using namespace std;
int n, m;
int a[104][104];
bool f[105];
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            if(a[i][j] == 0){
                f[j]=true;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(f[j] == false){
                cout << a[i][j] << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}
