#include <iostream>
using namespace std;
int n, k, c = 0;
int v[100004];
int f[100004];
int km = 0;
int nrc =0;
int main()
{
    cin >> n >> k;
    v[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    for(int i = 1; i <= n; i++){
        f[v[i]]++;
        if(f[v[i]] == 1){
            nrc++;
        }
        while(nrc == k){
            c += n-i+1;
            i++;
            f[v[i-k]]--;
            if(f[v[i-k]] == 0){
                f[v[i-k]]++;
                nrc--;
            }
        }
    }
    cout << c;
    return 0;
}
