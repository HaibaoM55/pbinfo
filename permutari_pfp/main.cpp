#include <iostream>
#include <algorithm>
using namespace std;
int n;
int v[16];
int main(){
	cin >> n;
    int j = n/2+n%2;
    for(int i = 1; i <= j; i++){
    	v[i] = 2*(i-1)+1;
    }
    do{
        for(int i = 1; i <= n; i++){
            if(i%2!=0){
               	cout << v[i/2+1] << ' ';
            }else{
                cout << i << ' ';
            }
        }
        cout << '\n';
    }while(next_permutation(v+1, v+j+1));
}
