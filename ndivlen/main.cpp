#include <iostream>
using namespace std;
int n;
int main()
{
    cin >> n;
    int x = n;
    int nrcif = 0;
    do{
        x = x / 10;
        nrcif++;
    }while(x > 0);
    cout << n;
    for(int i=nrcif; i < n; i++){
        cout<<0;
    }
    return 0;
}
