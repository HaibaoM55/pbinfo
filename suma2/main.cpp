#include <iostream>
using namespace std;
int n, k;
int v[1004];
int main(){
	cin >> n;
    for(int i = 1; i <= n; i++){
    	cin >> v[i];
    }
    int p1 = -1, p2 = -1;
    for(int i = 1; i <= n; i++){
        if(v[i] % 2 == 0){
			p1 = i;
            break;
        }
    }
    for(int i = n; i >= 1; i--){
        if(v[i] % 2 == 0){
        	p2 = i;
            break;
        }
    }
    if(p1 == -1){
    	cout << "NU EXISTA";
    }else{
        int s = 0;
        for(int i = p1; i <= p2; i++){
        	s += v[i];
        }
        cout << s;
    }
    return 0;
}
