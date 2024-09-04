#include <iostream>
#include <algorithm>
using namespace std;
int n;
int a[1000001];
int nrdiv = 0;
int va = 0;
int main()
{
    cin >> n;
    for(int i = 1; i*i <= n; i++){
        if(n % i == 0){
            nrdiv++;
            a[nrdiv] = i;
            if(i*i < n){
                nrdiv++;
                a[nrdiv] = n/i;
            }
        }
    }
    sort(a+1, a+nrdiv+1);
    va = 1;
    cout << 1 << ' ';
    for(int i = 2; i <= nrdiv; i++){
        if(a[i] % va == 0){
            cout << a[i] << ' ';
            va = a[i];
        }
    }
    return 0;
}
