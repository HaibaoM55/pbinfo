#include <iostream>
#include <algorithm>
using namespace std;
int n;
int v[203];
int main(){
    cin>>n;
    for(int i = 1; i <= n; i++){
    cin>>v[i];
    }
    int nr=0;
    for(int i = 1; i < n; i++){
        for(int j = i+1; j <= n; j++){
            if(__gcd(v[i], v[j]) == 1){
                nr++;
            }

        }
    }
    cout << nr;
    return 0;
}
