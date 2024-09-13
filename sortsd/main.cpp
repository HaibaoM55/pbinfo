#include <iostream>
#include <algorithm>
using namespace std;
int n;
struct xd{
    int n, div=0;
}v[1004];
bool compara(xd a, xd b){
    if(a.div < b.div){
        return true;
    }else if(a.div == b.div){
        if(a.n < b.n){
            return true;
        }
    }
    return false;
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i].n;
        for(int j = 1; j*j <= v[i].n; j++){
            if(v[i].n % j == 0){
                v[i].div += j;
                if(j*j < v[i].n){
                    v[i].div += v[i].n/j;
                }
            }
        }
    }
    sort(v+1, v+n+1, compara);
    for(int i = 1; i <= n; i++){
        cout << v[i].n << " ";
    }
    return 0;
}
