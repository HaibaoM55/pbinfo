#include <iostream>
using namespace std;
int n;
int main(){
	cin >> n;
    bool prim = true;
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0){
        	prim = false;
        	break;
        }
    }
    if(n <= 1){
    	prim = false;
    }
    if(prim){
    	cout << "DA";
    }else{
    	cout << "NU";
    }
    return 0;
}
