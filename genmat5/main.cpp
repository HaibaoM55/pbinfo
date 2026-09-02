#include <iostream>
using namespace std;
int n, a[25][25];
int main(){
    cin >> n;
    int x = n;
    int nrc =0;
    do{
        nrc++;
        n = n/10;
    }while(n);
    for(int i = 1; i <= nrc; i++){
        n = x;
        do{
            cout << n%10 << ' ';
            n = n/10;
        }while(n);
        cout << '\n';
    }
    return 0;
}
