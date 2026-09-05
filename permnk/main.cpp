#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int n, k;
int v[14];
int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        v[i] = i;
    }
    do{
        bool ok = true;
        for(int i = 2; i <= n; i++){
            if(abs(v[i]-v[i-1]) > k){
                ok = false;
                break;
            }
        }
        if(ok){
            for(int i = 1; i <= n; i++){
                cout << v[i] << ' ';
            }
            cout << '\n';
        }
    }while(next_permutation(v+1, v+n+1));
    return 0;
}
