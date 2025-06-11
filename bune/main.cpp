#include <iostream>
using namespace std;
int x, y;
int cifminx=10, cifminy=10;
int cifmaxx=0, cifmaxy=0;
int main(){
    cin >> x >> y;
    do{
        cifminx = min(cifminx, x%10);
        cifmaxx = max(cifmaxx, x%10);
        x = x/10;
    }while(x > 0);
    do{
        cifminy = min(cifminy, y%10);
        cifmaxy = max(cifmaxy, y%10);
        y = y/10;
    }while(y > 0);
    if(cifmaxx == cifminy){
        cout << cifmaxx;
    }
    else{
        if(cifmaxy == cifminx){
            cout << cifmaxy;
        }
        else{
            cout << "NU";
        }
    }
    return 0;
}
