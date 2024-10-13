#include <iostream>
#include <math.h>
using namespace std;
int n, b, r;
int main()
{
    cin >> n >> b >> r;
    int p = pow(10, n-1);
    int nr = b+r;
    while(nr < p){
        nr += b;
    }
    if(nr <= p*10){
        cout << nr;
    }else{
        cout << -1;
    }
    return 0;
}
