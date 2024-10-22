#include <iostream>
#include <string.h>
using namespace std;
int n;
int nrc = 0;
int v[13];
int main()
{
    cin >> n;
    /*bool z = false;
    for(int i = 1; i <= 1000; i++){
        int x = i;
        bool vesel = true, trist=true;
        do{
            if(x%2==0){
                trist = false;
            }else{
                vesel = false;
            }
            x = x / 10;
        }while(x > 0);
        if(trist){
            z = true;
            cout << i <<' ';
        }else if(vesel){
            if(z){
                cout << i << '\n';
                z = false;
            }
        }
    }*/
    int x = n;
    int p = 1;
    while(x >= 10){
        p = p*10;
        x = x/10;
    }
    if(x != 9){
        cout << p*(x+1);
    }else{
        cout<<p*20;
    }
    return 0;
}
