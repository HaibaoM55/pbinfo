#include <iostream>
#include <algorithm>
using namespace std;
int n;
int v[17];
int p[17], np[17];
bool ep[17];
bool esteprim(int x){
    if(x < 2){
        return false;
    }
    for(int i = 2; i*i <= x; i++){
        if(x % i == 0){
            return false;
        }
    }
    return true;
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        ep[i] = esteprim(v[i]);
        if(ep[i]){
            p[0]++;
            p[p[0]] = v[i];
        }else{
            np[0]++;
            np[np[0]] = v[i];
        }
    }
    sort(np+1, np+np[0]+1);
    do{
        np[0] = 0;
        p[0] = 0;
        for(int i = 1; i <= n; i++){
            if(ep[i]){
                p[0]++;
                cout << p[p[0]];
            }else{
                np[0]++;
                cout << np[np[0]];
            }
            cout << ' ';
        }
        cout << '\n';
    }while(next_permutation(np+1, np+np[0]+1));
    return 0;
}
