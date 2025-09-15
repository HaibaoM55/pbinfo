#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n , cnt = 0 , x , y ;
    cin >> n ;
    int a[202];
    for(int i = 1 ; i <= n ; i++)
        cin >> a[i];
    int z = n;
    int nr = 0;
    for(int i = 1; i <= n/2; i++){
        if(__gcd(a[i], a[z]) == 1){
            nr++;
        }
        z--;
    }
    cout << nr ;
}
