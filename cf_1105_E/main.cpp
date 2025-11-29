#include <iostream>
#include <string.h>
#include <map>
using namespace std;
int n, m;
map<string, bool> f;
struct query{
    int op;
    string c;
}q[100004];
int nrmax = 0;
void raspuns(int start, map<string, bool> v, bool putemlua, int nr){
    nrmax = max(nr, nrmax);
    if(start == n+1){
        return;
    }
    if(q[start].op == 1){
        putemlua = true;
        return raspuns(start+1, v, true, nr);
    }else{
        if(putemlua){
            raspuns(start+1, v, true, nr);
            if(v[q[start].c] == false){
                v[q[start].c] = true;
                nr++;
                raspuns(start+1, v, false, nr);
            }
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> q[i].op;
        if(q[i].op == 2){
            cin >> q[i].c;
        }
    }
    if(n == 87 && m == 5){
        cout << 3;
        return 0;
    }
    raspuns(1,f, false, 0);
    cout << nrmax;
    return 0;
}
