#include <iostream>
using namespace std;
int n,x;
int f[10];
int main()
{
    cin >> n;
    for(int i  =  1; i <= n; i++){
        cin >> x;
        while(x > 9){
            x = x/10;
        }
        f[x]++;
    }
    for(int j = 1; j <= f[1]; j++){
        cout << 1;
    }
    for(int j = 1; j <= f[0]; j++){
        cout << 0;
    }
    for(int i = 2; i <= 9; i++){
        for(int j = 1; j <= f[i]; j++){
            cout << i;
        }
    }
    return 0;
}
