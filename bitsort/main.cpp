#include <iostream>
#include <bitset>
using namespace std;
int n, x;
bitset<300004> f;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x;
        f[x]=true;
    }
    for(int i = 1; i <= 300000; i++){
        if(f[i]){
            cout << i << ' ' ;
        }
    }
    return 0;
}
