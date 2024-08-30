#include <iostream>
using namespace std;
long long n;
int main()
{
    cin >> n;
    //x*(x-1)/2 < n <= x*(x+1)/2
    for(long long x = 1; x <= 200000; x++){
        long long p1 = x*(x-1)/2;
        long long p2 = x*(x+1)/2;
        if(p1 < n && n <= p2){
            cout << x;
            break;
        }
    }
    return 0;
}
