#include <iostream>
#include <iomanip>
using namespace std;
int x, y, z;
int main(){
	cin >> x >> y >> z;
    int r1 = x+y+z;
	cout << r1/3 << '.';
    if(r1 % 3 == 0){
    	cout <<"00";
    }else if(r1 % 3 == 1){
    	cout << "33";
    }else{
        cout << "66";
    }
}
