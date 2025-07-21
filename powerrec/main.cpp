#include <iostream>
using namespace std;
int pwr(int a, int b){
    if(b == 0){
        return 1;
    }
    if(b == 1){
        return a;
    }else{
        return a*pwr(a, b-1);
    }
}
int x, y;
int main()
{
    cin >> x >> y;
    cout << pwr(x, y);
    return 0;
}
