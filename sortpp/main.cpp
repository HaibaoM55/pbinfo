#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int n,z=0;
int v[1004],a[1004];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        int sq = sqrt(v[i]);
        if(sq*sq == v[i]){
            z++;
            a[z] = v[i];
        }
    }
    sort(a+1, a+z+1);
    z = 0;
    for(int i = 1; i <= n; i++){
        int sq = sqrt(v[i]);
        if(sq*sq == v[i]){
            z++;
            cout << a[z] << ' ';
        }else{
            cout << v[i] << ' ';
        }
    }
}
