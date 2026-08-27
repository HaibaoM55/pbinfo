#include <iostream>
using namespace std;
int n;
int main(){
	cin >> n;
    while(n % 2 == 0){
   		n = n/2;
    }
    if(n == 1){
    	cout << "DA";
    }else{
     	cout << "NU";
    }
    return 0;
}
