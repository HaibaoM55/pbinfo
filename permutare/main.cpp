#include <iostream>
using namespace std;
int n, x;
int f[104];
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x;
        f[x]++;
    }
    for(int i = 1; i <= n; i++){
        if(f[i] != 1){
            cout << "NU";
            return 0;
        }
    }
    cout << "DA";
    return 0;
}
