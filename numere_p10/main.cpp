#include <iostream>
using namespace std;
int n, x, rasp = 0;
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> x;
		if(x == 10 || x == 100 || x == 1000 || x == 10000 || x == 100000){
			rasp++;
		}
	}
	cout << rasp;
	return 0;
}
