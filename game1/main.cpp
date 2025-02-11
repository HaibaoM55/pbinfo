#include <iostream>
#include <bitset>
using namespace std;
int t, g;
int main()
{
    cin >> t >> g;
    for(int i = 1; i <= g; i++){
        int x;
        cin >> x;
        if(t == 1){
            int ex = 0;
            while(x % 2 == 0){
                x = x/2;
                ex++;
            }
            if(ex % 2 == 0){
                cout << "1\n";
            }else{
                cout << "0\n";
            }
        }else{
            int ex = 0;
            while(x % 2 == 0){
                x = x/2;
                ex++;
            }
            if((x == 1 && ex % 2 != 0) || (ex % 2 == 0 && x > 1)){
                cout << "1\n";
            }else{
                cout << "0\n";
            }
        }
    }
    return 0;
}
