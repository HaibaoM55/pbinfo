#include <iostream>
using namespace std;
int n;
int vmax = 0, st, dr;
int v[1001];
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    for(int i = 1; i <= n-1; i++){
        for(int j = n; j >= i; j--){
            if(v[j] == v[i]){
                if(j-i+1 > vmax){
                    vmax = j-i+1;
                    st = i;
                    dr = j;
                }
                break;
            }
        }
    }
    cout << st << ' ' << dr;
    return 0;
}
