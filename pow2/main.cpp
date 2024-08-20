#include <iostream>
#include <algorithm>
using namespace std;
int n;
int pow2[31];
int v[100004];
int nr = 0;
int main()
{
    pow2[0] = 1;
    for(int i = 1; i <= 30; i++){
        pow2[i] = pow2[i-1]*2;
    }
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    sort(v+1, v+n+1);
    int p = 1;
    for(int i = 1; i <= n-1; i++){
        for(int j = p; j <= 30; j++){
            int x = pow2[j]-v[i];
            if(x < v[i]){
                p++;
                continue;
            }
            int p1 = i+1, p2 = n;
            while(p1 <= p2){
                int mij = (p1+p2)/2;
                if(v[mij] < x){
                    p1 = mij+1;
                }else{
                    p2 = mij-1;
                }
            }
            int x1 = p1;
            p1 = i+1;
            p2 = n;
            while(p1 <= p2){
                int mij = (p1+p2)/2;
                if(v[mij] <= x){
                    p1 = mij+1;
                }else{
                    p2 = mij-1;
                }
            }
            nr += p1-x1;
        }
    }
    cout << nr;
    return 0;
}
