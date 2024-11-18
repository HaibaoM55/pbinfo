#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int v[100008];
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n+m; i++){
        cin >> v[i];
    }
    sort(v+1, v+n+m+1);
    long long s = 0;
    for(int i = m+1; i <= n+m; i++){
        s = s + v[i];
    }
    cout << s;
    return 0;
}
