#include <iostream>
using namespace std;
int primacif(int x){
    while(x > 9){
    	x = x/10;
    }
    return x;
}
int sumacif(int x){
    if(x == 0){
        return 0;
    }
    return x%10+sumacif(x/10);
}
int n,x;
int main(){
	cin >> n;
    for(int i = 1; i <= n; i++){
    	cin >> x;
        if(primacif(x) % 2 == 0){
        	x = sumacif(x);
        }
        cout << x << ' ';
    }
    return 0;
}
