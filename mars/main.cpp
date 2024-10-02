#include <iostream>
using namespace std;
int n, m;
int s, d, x;
int mars[200004];
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> s >> d >> x;
        mars[s] += x;
        mars[d+1] -= x;
    }
    mars[0] = 0;
    for(int i = 1; i <= n; i++){
        mars[i] += mars[i-1];
    }
    for(int i = 1; i <= n; i++){
        cout << mars[i] << ' ';
    }
    return 0;
}
