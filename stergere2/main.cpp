#include <iostream>
using namespace std;
int n;
int v[1004], vmin = 2147483647;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        if(v[i] < vmin){
            vmin = v[i];
        }
    }
    for(int i = 1; i <= n; i++){
        if(v[i] > vmin){
            cout << v[i] << ' ';
        }
    }
    return 0;
}
