#include <iostream>
using namespace std;
int t, a, b;
int nrp = 0;
long long prm[400004];
int s[1000004];
bool ciur[1000004];
int main()
{
    for(int i = 2; i <= 500000; i++){
        if(ciur[i] == false){
            nrp++;
            prm[nrp] = i;
            for(int j = i; j <= 500000/i; j++){
                ciur[j*i] = true;
            }
        }
    }
    for(int i = 1; i <= nrp-1; i++){
        for(int j = i; j <= nrp; j++){
            long long x = prm[i]*prm[j];
            if(x <= 1000000){
                s[x] = 1;
            }else{
                break;
            }
        }
    }
    for(int i = 1; i <= 1000000; i++){
        s[i] = s[i-1]+s[i];
    }
    cin >> t;
    for(int i = 1; i <= t; i++){
        int a, b;
        cin >> a >> b;
        cout << s[b]-s[a-1] << ' ';
    }
    return 0;
}
