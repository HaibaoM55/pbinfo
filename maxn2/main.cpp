#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n;
int v[1004];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    sort(v+1, v +n+1);
    long long s = 0;
    for(int i = 1; i <= n/2; i++){
        v[i] = -v[i];
        s += v[i];
    }
    for(int i = n/2+1; i <= n; i++){
        s += v[i];
    }
    cout << s;
    return 0;
}
