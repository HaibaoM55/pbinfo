#include <iostream>
#include <string.h>
using namespace std;
char x[67];
int p, q;
int main(){
    cin >> x >> p >> q;
    int l = strlen(x);
    if(p+q > l){
    	cout << "imposibil";
        return 0;
    }
    for(int i = p-1; i >= 0; i--){
		cout << x[i];
    }
    for(int i = p; i <= l-q-1; i++){
    	cout << x[i];
    }
    for(int i = l-1; i > l-q-1; i--){
    	cout << x[i];
    }
	return 0;
}
