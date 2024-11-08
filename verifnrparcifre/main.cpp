#include <iostream>
using namespace std;
int n;
int x;
bool da = true;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x;
        int cif = 0;
        do{
            cif++;
            x = x/10;
        }while(x > 0);
        if(cif % 2 != 0){
            da = false;
            break;
        }
    }
    if(da){
        cout <<"DA";
    }else{
        cout <<"NU";
    }
    return 0;
}
