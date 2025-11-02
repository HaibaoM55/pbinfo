#include <iostream>
using namespace std;
void perfect(int a, int b){
    bool ok = false;
    for(int i = b; i >= a; i--){
        if(i == 1){
            continue;
        }
    	int s = 1;
        for(int j = 2; j*j <= i; j++){
            if(i % j == 0){
            	s += j;
                if(j*j < i){
                	s += i/j;
                }
            }
        }
        if(s == i){
        	cout << i << ' ';
        	ok = true;
        }
    }
    if(!ok){
        cout << "nu exista";
    }
}/*
int main(){
    perfect(5, 30);
    return 0;
}*/
