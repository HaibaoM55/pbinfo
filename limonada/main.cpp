#include <iostream>
using namespace std;
int n, x;
int f[30];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x;
        if(x == 5){
            f[5]++;
        }else if(x == 10){
            f[5]--;
            f[10]++;
        }else{
            f[5]--;
            f[10]--;
            f[20]++;
        }
        if(f[5] < 0 || f[10] < 0){
            cout << "NEY";
            return 0;
        }
    }
    cout << "YEAH";
	return 0;
}
