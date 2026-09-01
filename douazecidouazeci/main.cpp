#include <iostream>
using namespace std;
int n, x;
bool dp[2021] = {};
int main(){
    cin >> n;
    dp[1] = true;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        for(int p = 2020; p >= 1; p--){
            if(dp[p] && p * x <= 2020){
				dp[p * x] = true;
            }
        }
    }
    if(dp[2020]){
        cout << "DA";
	}else{
        cout << "NU";
    }
    return 0;
}
