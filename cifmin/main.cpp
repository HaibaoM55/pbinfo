#include <iostream>
using namespace std;
int n, x;
int f[11];
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x;
        int vmin = 10;
        do{
            vmin = min(vmin, x%10);
            x = x/10;
        }while(x > 0);
        f[vmin]++;
    }
    for(int i = 1; i <= 9; i++){
        if(f[i] > 0){
            cout << i;
            f[i]--;
            break;
        }
    }
    for(int i = 0; i <= 9; i++){
        while(f[i]){
            cout << i;
            f[i]--;
        }
    }
    return 0;
}
