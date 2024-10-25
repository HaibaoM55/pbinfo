#include <iostream>
using namespace std;
int n;
int x, y;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x >> y;
        int aux = min(x, y);
        y = max(x, y);
        x = aux;
        int nrv = 0;
        for(int nr = 1; nr <= y; nr = nr*2){
            if(nr >= x){
                nrv = nr;
            }
        }
        cout << nrv << '\n';
    }
    return 0;
}
