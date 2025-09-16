#include <iostream>
#include <math.h>
using namespace std;
int n;
int main(){
    long double nr = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        nr += log10(i);
    }
    nr = nr*n;
    long long rez = nr+1;
    cout << rez;
    return 0;
}
