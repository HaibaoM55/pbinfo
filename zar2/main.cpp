#include <iostream>
#include <iomanip>
using namespace std;
int n, a, b;
long double dp[604];
int main(){
    cin >> n >> a >> b;
    dp[0] = 1.0L;
    for(int i = 1; i <= n; i++){
        long double aux[601] = {};
        for(int s = 0; s <= 6*(i-1); s++){
            for(int zar = 1; zar <= 6; zar++){
                aux[s+zar] += dp[s]/6.0L;
            }
        }
        for(int s = 0; s <= 6 * i; s++){
            dp[s] = aux[s];
        }
    }
    long double rasp = 0;
    for(int i = a; i <= b; i++){
        rasp += dp[i];
    }
    cout << fixed << setprecision(6) << rasp;
    return 0;
}
