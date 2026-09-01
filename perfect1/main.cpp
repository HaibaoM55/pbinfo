#include <fstream>
using namespace std;
ifstream cin("perfect1.in");
ofstream cout("perfect1.out");
int n, x;
bool dp[8129];
bool esteperf(int k){
    int s = 0;
    for(int i = 1; i*i <= k; i++){
        if(k % i == 0){
        	s += i;
            if(i*i < k){
            	s += k/i;
            }
        }
    }
    return 2*k==s;
}
int main(){
    cin >> n;
    dp[1] = true;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        for(int p = 8128; p >= 1; p--){
            if(dp[p] && p * x <= 8128){
				dp[p * x] = true;
            }
        }
    }
    for(int i = 8128; i >= 1; i--){
        if(dp[i] && esteperf(i)){
        	cout << i;
            return 0;
        }
    }
    cout << "NU";
    return 0;
}
