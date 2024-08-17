#include <iostream>
#include <algorithm>
using namespace std;
long long n, nr = 1;
int v[100004];
long long s = 0;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    sort(v+1, v+n+1);
    for(int i = 1; i <= n; i++){
        if(v[i] == v[i-1]){
            nr++;
        }else{
            s += ((nr-1)*nr)/2; //1+2+...+nr-1
            nr = 1;
        }
    }
    s += ((nr-1)*nr)/2; //1+2+...+nr-1
    nr = 0;
    cout << s;
    return 0;
}
