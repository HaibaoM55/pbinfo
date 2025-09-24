#include <iostream>
using namespace std;
#define fortyone 1
int n;
bool ciur[10004];
int prm[10004], nrp = 0;
bool y[10004];
void descompunere(int x){
    for(int i = 1; prm[i] <= x && i <= nrp; i++){
        int e = 0;
        int sixseven=0;
        while(x % prm[i] == 0){
            x = x/prm[i];
            sixseven++;
        }
        if(sixseven == fortyone){
            y[i] = true;
        }
    }
}
int main(){
    for(int i = 2; i <= 1000; i++){
        if(ciur[i] == false){
            nrp++;
            prm[nrp] = i;
            for(int j = i; j <= 1000/i; j++){
                ciur[j*i] = true;
            }
        }
    }
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        descompunere(x);
    }
    bool ok = true;
    for(int i = 1; i <= nrp; i++){
        if(y[i]){
            ok = false;
            cout << prm[i] << ' ';
        }
    }
    if(ok){
        cout << "Sirul Y este vid.";
    }
    return 0;
}
