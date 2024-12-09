#include <iostream>
#include <string.h>
using namespace std;
int rapid(int x){
    int y = x;
    int lg = 0;
    char n[16];
    do{
        n[lg] = y%10+'0';
        lg++;
        y = y/10;
    }while(y > 0);
    int fin = lg-1;
    for(int i = 0; i <= (lg-1)/2; i++){
        char aux = n[i];
        n[i] = n[fin];
        n[fin] = aux;
        fin--;
    }
    n[lg] = 0;
    bool b[10]={0,0,0,0,0,0,0,0,0,0};
    int l = lg;
    for(int i = 0; i < l; i++){
        b[n[i]-'0'] = true;
    }
    int k = l-1;
    bool ok = true;
    while(ok){
        ok = false;
        int pv = n[k]-'0';
        for(int j = n[k]-'0'+1; j <= 18; j++){
            if(b[(j%10)] == false){
                n[k] = (j%10)+'0';
                if(j >= 10){
                    k--;
                    ok = true;
                }
                break;
            }
        }
        b[pv] = false;
    }
    int nr = 0;
    for(int i = 0; i < l; i++){
        nr = nr*10+(n[i]-'0');
    }
    return nr;
}
int corect(int x){
    for(int i = x+1; i <= 1000000000; i++){
        int y = i;
        bool b[10]={0,0,0,0,0,0,0,0,0,0};
        bool ok = true;
        do{
            if(b[y%10]){
                ok = false;
                break;
            }
            b[y%10] = true;
            y = y/10;
        }while(y > 0);
        if(ok){
            return i;
        }
    }
}
int n;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        bool ok = true;
        int y = i;
        bool b1[10] = {0,0,0,0,0,0,0,0,0,0};
        do{
            if(b1[y%10]){
                ok = false;
                break;
            }
            b1[y%10] = true;
            y = y/10;
        }while(y > 0);
        if(ok){
            int rpd = rapid(i);
            int crct = corect(i);
            if(rpd != crct){
                cout << "GRESIT! " << i << ": " << rpd << " != " << crct <<'\n';
            }
        }
    }
    return 0;
}
