#include <iostream>
using namespace std;
int n, x, o=0;
int v[104];
int main()
{
    cin >> n >> x;
    do{
        o = o*10+(x%10);
        x = x/10;
    }while(x > 0);
    bool ok = false;
    for(int i = 2; i <= n; i++){
        cin >> x;
        if(o == x){
            ok = true;
            break;
        }
    }
    if(ok){
        cout << "DA";
    }else{
        cout << "NU";
    }
    return 0;
}
