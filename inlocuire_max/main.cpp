#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int n;
char x[20];
int v[1001];
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x;
        int l = strlen(x);
        sort(x, x+l);
        v[n-i+1] = 0;
        for(int j = l-1; j >= 0; j--){
            v[n-i+1] = v[n-i+1]*10+x[j]-'0';
        }
    }
    for(int i = 1; i <= n; i++){
        cout << v[i] << ' ';
    }
    return 0;
}
