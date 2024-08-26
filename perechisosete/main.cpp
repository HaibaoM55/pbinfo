#include <iostream>
using namespace std;
int n, nr = 0;
int f[102];
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        f[x]++;
    }
    for(int i = 1; i <= 100; i++){
        nr += f[i]/2;
    }
    cout << nr;
    return 0;
}
