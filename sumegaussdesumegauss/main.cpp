#include <iostream>
using namespace std;
int n;
long long x, s;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x;
        long long x1 = x+1, x2 = x+2;
        if(x % 2 == 0){
            x /= 2;
        }else{
            x1 /= 2;
        }
        if(x % 3 == 0){
            x /= 3;
        }else if(x1 % 3 == 0){
            x1 /= 3;
        }else{
            x2 /= 3;
        }
        s = x*x1*x2;
        cout << s << " ";
    }
    return 0;
}
