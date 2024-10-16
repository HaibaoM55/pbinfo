#include <iostream>
using namespace std;
int n,m,x;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> m;
        int o = -1000000000;
        bool ok = true;
        for(int j = 1; j <= m; j++){
            cin >> x;
            if(x < o && ok){
                ok = false;
            }else{
                o = x;
            }
        }
        cout << ok << ' ';
    }
    return 0;
}
