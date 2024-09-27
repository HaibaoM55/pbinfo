#include <iostream>
using namespace std;
int n;
int a[304][304];
int t[304];
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int x;
            cin >> x;
            a[i][j]=a[i-1][j]+x;
        }
    }
    int vmax = -300001;
    for(int i = 1; i <= n; i++){
        for(int i1 = i; i1 <= n; i1++){
            for(int j = 1; j <= n; j++){
                t[j] = a[i1][j]-a[i-1][j];
            }
            int s = 0;
            for(int j = 1; j <= n; j++){
                s += t[j];
                if(s > vmax){
                    vmax = s;
                }
                if(s < 0){
                    s = 0;
                }
            }
        }
    }
    cout << vmax;
    return 0;
}
