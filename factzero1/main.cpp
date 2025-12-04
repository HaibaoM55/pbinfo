#include <iostream>
using namespace std;
int n;
int s = 0;
int main(){
    cin >> n;
    s = 1;
    int nr =0;
    for(int p=5; p <= n; p=p*5){
        nr += n/p;
    }
    for(int i = 1; i <= n; i++){
        int cpy = i;
        while(cpy % 2 == 0 && nr > 0){
        	cpy /= 2;
            nr--;
        }
        while(cpy % 5 == 0){
        	cpy /= 5;
        }
        s = s*cpy;
        s = s%10;
    }
    cout << s;
    return 0;
}
