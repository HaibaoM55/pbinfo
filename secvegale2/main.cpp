#include <iostream>
using namespace std;
int n;
long long s = 0;
int v[100004];
int main()
{
    cin >> n;
    int z = 1;
    cin >> v[1];
    for(int i = 2; i <= n; i++){
        cin >> v[i];
        s += z;
        if(v[i] == v[i-1]){
            z++;
        }else{
            z = 1;
        }
    }
    s += z;
    cout << s;
    return 0;
}
