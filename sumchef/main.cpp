#include <iostream>
#include <string.h>
using namespace std;
int n;
long long s = 0;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        char b[5];
        cin >> b;
        int l = strlen(b);
        for(int j = 0; j < l; j++){
            int x = b[j]-'0';
            s += x*x*x;
        }
    }
    cout << s;
    return 0;
}
