#include <iostream>
using namespace std;
int n;
int v[1004];
bool esteprim(int x){
    if(x == 1){
        return false;
    }
    for(int i = 2; i*i <= x; i++){
        if(x % i == 0){
         	return false;
        }
    }
	return true;
}
int rasp(int p1, int p2){
    if(p1 > p2){
        return 0;
    }
    if(p1 == p2){
        if(esteprim(v[p1])){
        	return v[p1];
        }else{
            return 0;
        }
    }else{
        int mij = (p1+p2)/2;
        return rasp(p1, mij)+rasp(mij+1, p2);
    }
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    cout << rasp(1, n);
}
