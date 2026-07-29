#include <iostream>
using namespace std;
long long n, m;
int main(){
    cin >> n >> m;
    if(n == 1){
        cout << "1 1";
        return 0;
    }else if(m == 0){
        cout << n << ' ' << n;
        return 0;
    }
    cout << n-min(n, m*2) << ' ';
    int rasp = 0;
    for(int i = 1; i <= n; i++){
        if(m <= 0){
            break;
        }
        rasp++;
        m -= i-1;
    }
    cout << n-rasp;
    return 0;
}
