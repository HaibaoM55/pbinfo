#include <iostream>
using namespace std;
int n, x;
int f[100];
long long s = 0;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x;
        int s= 0;
        do{
            s = s + x%10;
            x = x/10;
        }while(x > 0);
        f[s]++;
    }
    for(int i = 0; i <= 81; i++){
        s = s+(f[i]*(f[i]-1))/2;
    }
    cout << s;
    return 0;
}
