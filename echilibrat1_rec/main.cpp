#include <iostream>
using namespace std;
int nrp(int x){
    if(x < 10){
    	return (int)(x%2==0);
    }
    return (int)(x%2==0)+nrp(x/10);
}
int nri(int x){
    if(x < 10){
    	return (int)(x%2==1);
    }
    return (int)(x%2==1)+nri(x/10);
}
int p, q;
int main(){
    cin >> p >> q;
    int s = 0;
    for(int i = p; i <= q; i++){
        if(nrp(i) == nri(i)){
        	s += i;
        }
    }
    cout << s;
	return 0;
}
