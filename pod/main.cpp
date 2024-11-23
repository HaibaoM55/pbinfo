#include <iostream>
using namespace std;
int n, m;
int a[1004][1004];
long long s = 0;
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    for(int j = 1; j <= m; j++){
        int minim = a[1][j];
        for(int i = 2; i <= n; i++){
            if(a[i][j] < minim){
                minim = a[i][j];
            }
        }
        s = s+minim;
    }
    cout << s;
    return 0;
}
