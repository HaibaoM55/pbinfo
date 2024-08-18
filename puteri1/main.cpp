#include <iostream>
using namespace std;
int n, k;
int x;
int s = 0;
int puteri[31], nrp = 0;
int main()
{
    cin >> n >> k;
    int clc = 1000000000/k;
    puteri[0] = 1;
    for(int i = 1; puteri[i-1] <= clc; i++){
        puteri[i] = puteri[i-1]*k;
        nrp++;
    }
    for(int i = 1; i <= n; i++){
        cin >> x;
        int old_pr= -1;
        bool ok = true;
        while(x > 0){
            int p1 = 0;
            int p2 = nrp;
            while(p1 <= p2){
                int mij = (p1+p2)/2;
                if(puteri[mij] > x){
                    p2 = mij-1;
                }else{
                    p1 = mij+1;
                }
            }
            if(p2 == old_pr){
                ok = false;
                break;
            }
            old_pr = p2;
            x = x-puteri[p2];
        }
        if(ok){
            s++;
        }
    }
    cout << s;
    return 0;
}
