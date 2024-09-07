#include <iostream>
#include <algorithm>
using namespace std;
int n, a, b;
int v[160005];
long long nr = 0;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    cin >> a >> b;
    sort(v+1, v+n+1);
    long long j = n;
    long long b1 = 0;
    for(int i=1; i<=n; i++){
        while(i<j && v[i]+v[j]>b){
            j--;
        }
        if(i<j){
            b1+=(j-i);
        }
    }
    long long a1 = 0;
    for(int i=1; i<=n; i++){
        while(i<j && v[i]+v[j]>(a-1)){
            j--;
        }
        if(i<j){
            a1+=(j-i);
        }
    }
    cout << b1-a1;
    return 0;
}
