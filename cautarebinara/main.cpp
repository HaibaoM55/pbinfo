#include <iostream>
using namespace std;
int n, m, x;
int v[25004];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    cin >> m;
    for(int i = 1; i <= m; i++){
        cin >> x;
        int p1 = 1, p2 = n;
        bool ok = false;
        while(p1 <= p2){
            int mij = (p1+p2)/2;
            if(v[mij] < x){
                p1 = mij+1;
            }else if(v[mij] == x){
                ok = true;
                break;
            }else{
                p2 = mij-1;
            }
        }
        cout << (int) ok << ' ';
    }
    return 0;
}
