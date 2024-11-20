#include <iostream>
using namespace std;
int p, n, k;
int gr, nr = 0;
int f[14];
bool b[14];
bool c[14];
int main()
{
    cin >> p >> n >> k;
    for(gr = 1; p > gr; gr++){
        p = p-gr;
    }
    if(gr % 2 == 1){
        cout << p*2+gr*(gr-1)-1;
    }else{
        p = gr-p+1;
        cout << p*2+gr*(gr-1)-1;
    }
    cout << '\n';
    for(int i = 1; i <= n; i++){
        int x = n*(n-1);
        int y = x+i*2-1;
        do{
            f[y%10]++;
            y = y/10;
        }while(y > 0);
    }
    int nr = 0;
    for(int i = 9; i >= 0; i--){
        if(f[i] >= 2){
            if(f[i] % 2 != 0){
                c[i] = true;
            }
            f[i] = f[i]/2;
            for(int j = 1; j <= f[i]; j++){
                cout << i;
            }
            b[i] = true;
        }
    }
    for(int i = 9; i >= 0; i--){
        if(c[i] || b[i] == false){
            cout << i;
            break;
        }
    }
    for(int i = 0; i <= 9; i++){
        if(b[i]){
            for(int j = 1; j <= f[i]; j++){
                cout << i;
            }
        }
    }
    cout << '\n';
    long long suma = 0;
    int grc = 0;
    for(gr = 1; suma <= k; gr++){
        int x = gr*(gr-1);
        //x+1*2-1+...+x+gr*2-1=x*gr+gr*(gr+1)-gr;
        suma = x*gr+gr*(gr+1)-gr;
        if(suma <= k){
            grc = gr;
        }
    }
    cout << grc;
    return 0;
}
