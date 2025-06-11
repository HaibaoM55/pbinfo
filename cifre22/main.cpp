#include <iostream>
using namespace std;
int n,x,nr,maxim=-1,maximnr;
int v[50];
int main() {
    cin>>n;
    for(int i = 1; i <= n; i++){
        int nrcif = 0;
        cin >> x;
        int copie = x;
        do{
            nrcif++;
            v[nrcif] = x%10;
            x = x/10;
        }while(x > 0);
        int asociat = 0;
        for(int j = nrcif; j >= 0; j--){
            if(v[j] % 2 == 0){
                asociat = asociat*10+v[j];
            }
        }
        if(asociat > maxim){
            maxim = asociat;
            maximnr = copie;
        }
        if(asociat == maxim){
            maximnr = max(maximnr, copie);
        }
    }
    cout<<maximnr;

}
