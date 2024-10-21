#include <iostream>
using namespace std;
int n, v[100003];
long long s = 0, s1;
int main()
{
    cin >> n;
    for(int i = 1; i <= n/2; i++){
        cin >> v[i];
        s1 = s1+v[i];
    }
    for(int i = n/2+1; i <= n; i++){
        cin >> v[i];
        s = s+(s1*v[i]);
    }
    cout << s;
    return 0;
}
