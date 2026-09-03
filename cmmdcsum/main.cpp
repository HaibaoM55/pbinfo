#include <iostream>
#include <algorithm>
using namespace std;
int n, a[24][24];
int s1=0,s2=0;
int main(){
	cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
        	cin >> a[i][j];
            if(j < i){
            	s1 += a[i][j];
            }else if(j > i){
            	s2 += a[i][j];
            }
        }
    }
    cout << __gcd(s1, s2);
}
