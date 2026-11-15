#include <iostream>
using namespace std;
int n, x, y;
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> x >> y;
		int p1 = x/3, p2 = y/3;
		if(x % 3 == 2){
            if(y >= 2*p1+3){
                cout << "filippo";
            }else if(y == 2*p1+2){
                cout << "draw";
            }else{
                cout << "tommaso";
            }
		}else{
            if(y >= 2*p1+2){
                cout << "filippo";
            }else if(y == 2*p1+1){
                cout << "draw";
            }else{
                cout << "tommaso";
            }
		}
		cout << '\n';
	}
	return 0;
}
