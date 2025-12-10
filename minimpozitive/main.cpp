#include <iostream>
using namespace std;
int x,vmin=2e9;
int main(){
    while(cin >> x){
       if(x==0)
           break;
        if(x>0)
            vmin = min(vmin, x);
}
    if(vmin==2e9){
cout<<"NU EXISTA";return 0;

    }

    cout <<vmin;
return 0;
}
