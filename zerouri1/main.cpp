#include <iostream>
using namespace std;
int n;
long long p=1;
int e2=0, e5=0;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        while(x % 2 == 0){
            x = x / 2;
            e2++;
        }
        while(x % 5 == 0){
            x = x / 5;
            e5++;
        }
        p = p*x;
        p = p%10;
    }
    if(e2 >= e5){
        e2 = e2-e5;
        for(int i = 1; i <= e2; i++){
            p = p * 2;
            p = p % 10;
        }
        cout << p;
    }else{
        cout << 5;
    }
    return 0;
}
