#include <iostream>
using namespace std;
int n;
int m, b, r;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> m >> b >> r;
        int t = 1;
        for(int i = 1; i <= m-1; i++){
            t = t*10+0;
            t = t%b;
        }
        cout << 1;
        for(int i = 1; i <= m-2; i++){
            cout << 0;
        }
        if(t <= r){
            cout << r-t;
        }else{
            cout << (b-t)+r;
        }
        cout << '\n';
    }
    return 0;
}
