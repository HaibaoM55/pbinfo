#include <iostream>
using namespace std;
char x;
int p;
int s = 0, nr = 0;
int main()
{
    while(cin >> x){
        if(x != '.'){
            p = x;
            s += p;
            nr++;
        }else{
            break;
        }
    }
    int ma = s/nr;
    cout << (char) ma;
    return 0;
}
