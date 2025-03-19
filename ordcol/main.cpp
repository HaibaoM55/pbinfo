#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int a[104][104];
struct poz{
    int val, j;
}v[104];
bool compara(poz a, poz b){
    if(a.val < b.val){
        return true;
    }
    return false;
}
int main()
{
    cin >> n >> m;
    for(int j = 1; j <= m; j++){
        cin >> a[1][j];
        v[j].val = a[1][j];
        v[j].j = j;
    }
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    sort(v+1, v+m+1, compara);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << a[i][v[j].j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
