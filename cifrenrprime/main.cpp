#include <iostream>
using namespace std;
int nrcifre(int x){
    if(x < 10){
    	return 1;
    }
    return nrcifre(x/10)+1;
}
bool esteprim(int x){
    if(x < 2){
    	return false;
    }
    for(int i = 2; i*i <= x; i++){
        if(x % i == 0){
        	return false;
        }
    }
    return true;
}
int n, x;
int nr = 0;
int main(){
	cin >> n;
    for(int i = 1; i <= n; i++){
    	cin >> x;
        if(esteprim(x)){
        	nr += nrcifre(x);
        }
    }
    cout << nr;
    return 0;
}
