#include <iostream>
using namespace std;
int k;
char x[35];
int s = 0;
int main()
{
    cin >> k;
    cin >> x;
    for(int i = 0; i < k; i++){
        s = s + (x[i]-'0');
    }
    int cif = s/k;
    int pvx = s%k;
    for(int i = 1; i <= k-pvx; i++){
        cout << cif;
    }
    for(int i = k-pvx+1; i <= k; i++){
        cout << cif+1;
    }
    return 0;
}
