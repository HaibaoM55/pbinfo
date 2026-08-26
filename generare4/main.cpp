#include <iostream>
using namespace std;
int n;
void scrie(int p, int q, int z){
    if(z > n) return;
    int mij = (p+q)/2;
    for(int i = p; i <= mij; i++){
    	cout << i << ' ';
    }
    scrie(q+1, q*2, z+1);
    for(int i = mij+1; i <= q; i++){
    	cout << i << ' ';
    }
}
int main(){
	cin >> n;
    scrie(1, 2, 1);
    return 0;
}
