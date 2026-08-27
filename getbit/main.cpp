#include <iostream>
using namespace std;
long long getbit(long long n, int b){
    long long bit = (n >> b) & 1LL;
    return bit;
}
int t;
long long n, b;
int main(){
    cin >> t;
    for(int i = 1; i <= t; i++){
    	cin >> n >> b;
        cout << getbit(n, b);
    }
    return 0;
}
