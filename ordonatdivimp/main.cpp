#include <iostream>
using namespace std;
int m,n;
int v[1004];
int rasp(int p1, int p2){
    if(p1 > p2){
        return 0;
    }
    if(p1 == p2){
        return v[p1] > v[p1-1];
    }else{
        int mij = (p1+p2)/2;
        return rasp(p1, mij)+rasp(mij+1, p2);
    }
}
int main(){
 	v[0] = -2e9;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    int r = rasp(1, n);
    if(r == n){
    	cout << "strict crescator";
    }else if(r == 1){
		cout << "strict descrescator";
    }else{
    	cout << "neordonat";
    }
    return 0;
}
