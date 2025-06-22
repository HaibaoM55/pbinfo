#include <iostream>
#include <bitset>
using namespace std;
bitset<30000004> benone;
int x;
int main(){
    while(cin >> x){
        if(benone[x]){
            cout << x;
            return 0;
        }
        benone[x] = true;
    }
    return 0;
}
