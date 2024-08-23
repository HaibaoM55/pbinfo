#include <iostream>
using namespace std;
int n, t, k;
int v[100004];
int nr = 0;
int main()
{
    cin >> n >> t >> k;
    int z = 0;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if(x > t){
            z++;
            v[z] = i;
        }
    }
    v[z+1] = n+1;
    int j = 1;
    for(int i = 1; i <= n; i++){
        if(v[j]-i  >= k){
            nr++;
        }else{
            i = v[j];
            j++;
        }
    }
    cout << nr;
    return 0;
}
