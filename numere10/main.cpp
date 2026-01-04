#include <iostream>
using namespace std;
int n;
int nrp=0, prmin=2e9, prmax=0;
bool esteprim(int x){
    if(x < 2){
        return false;
    }
    for(int i = 2; i*i <= x; i++){
        if(x %  i == 0){
        	return false;
        }
    }
    return true;
}
int x;
int main(){
	cin >> n;
    for(int i = 1; i <= n; i++){
    	cin >> x;
        if(esteprim(x)){
        	nrp++;
            prmin = min(prmin, x);
            prmax = max(prmax, x);
        }
    }
    cout << nrp << ' ' << prmin << ' ' << prmax;
    return 0;
}
