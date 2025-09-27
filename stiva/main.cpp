#include <iostream>
#include <string.h>
using namespace std;
int n;
int stiva[1004];
int dr =0;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        char x[6];
        cin >> x;
        if(strcmp(x, "push") == 0){
            int y;
            cin >> y;
            dr++;
            stiva[dr] = y;
        }else if(strcmp(x, "pop") == 0){
            dr--;
        }else{
            cout << stiva[dr] << '\n';
        }
    }
    return 0;
}
