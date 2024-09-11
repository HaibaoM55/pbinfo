#include <iostream>
#include <math.h>
using namespace std;
int n;
int v[26];
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        int p = sqrt(v[i]);
        if(p*p == v[i]){
            cout << p << ' ' << v[i] << ' ';
        }else{
            cout << v[i] << ' ';
        }
    }
    return 0;
}
