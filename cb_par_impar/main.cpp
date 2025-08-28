#include <iostream>
#include <unordered_map>
using namespace std;
int n, m;
int x, y;
unordered_map<int, bool> fi;
unordered_map<int, bool> fp;
int main(){
    cin >> n;
    for(int i = 1; i <= n/2; i++){
        cin >> x;
        if(x % 2 == 0){
            fp[x] = true;
        }
    }
    for(int i = n/2+1; i <= n; i++){
        cin >> x;
        if(x % 2 == 1){
            fi[x] = true;
        }
    }
    cin >> m;
    int nrp = 0, nri = 0;
    for(int i = 1; i <= m; i++){
        cin >> y;
        if(y % 2 == 0 && fp[y]){
            nrp++;
        }
        if(y % 2 == 1 && fi[y]){
            nri++;
        }
    }
    cout << nrp << ' ' << nri;
    return 0;
}
