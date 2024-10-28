#include <iostream>
using namespace std;
int f1, f2, f;
int x;
int fx[1001];
int n=1;
int main()
{
    cin >> x;
    f1 = 1;
    fx[1] = 1;
    for(int i = 2; f <= x; i++){
        if(i % 2 == 0){
            f = 1+f1;
            f2 = f1;
            f1 = f;
        }else{
            f = 1+2*f2;
            f2 = f1;
            f1 = f;
        }
        if(f <= x){
            n = i;
            fx[i] = f;
        }
    }
    for(int i = n; i >= 1; i--){
        cout << fx[i] << ' ';
    }
    return 0;
}
