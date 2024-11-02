#define MOD 666013
#include <iostream>
using namespace std;
long long n, s = 0;
int main()
{
    cin >> n;
    long long nx = n;
    long long n1 = n + 1;
    long long n11 = n + 1;
    long long n2 = n + 2;
    if(nx % 3 == 0){
        nx = nx / 3;
    }else if(n1 % 3 == 0){
        n1 = n1 / 3;
    }else{
        n2 = n2 / 3;
    }
    if(nx % 2 == 0){
        nx = nx / 2;
        n2 = n2 / 2;
    }else{
        n1 = n1 / 2;
        n11 = n11 / 2;
    }
    s = nx%MOD;
    s = (s*n1)%MOD;
    s = (s*n11)%MOD;
    s = (s*n2)%MOD;
    cout << s;
    return 0;
}
