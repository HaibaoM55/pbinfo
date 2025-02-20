#include <iostream>
using namespace std;
int n, x;
int nrd[1004];
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x;
        nrd[i] = 1;
        if(x > 1){
            nrd[i] += x;
        }
        for(int j = 2; j*j <= x; j++){
            if(x % j == 0){
                nrd[i] += j;
                if(j*j < x){
                    nrd[i] += x/j;
                }
            }
        }
    }
    int nrp =0;
    for(int i = 1; i <= n-1; i++){
        for(int j = i+1; j <= n; j++){
            if(nrd[i] == nrd[j]){
                nrp++;
            }
        }
    }
    cout << nrp;
    return 0;
}
