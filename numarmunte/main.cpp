#include <iostream>
#include <string.h>
using namespace std;
int n;
char x[256];
int main(){
    cin >> n;
    for(int i =  1; i <= n; i++){
        cin >> x;
        int l = strlen(x);
        int j;
        bool ok = false;
        for(j =1; j < l-1; j++){
            bool ok1 = true;
            for(int k = 0; k < j; k++){
                if(x[k] >= x[k+1]){
                    ok1 = false;
                    break;
                }
            }
            for(int k = j; k < l-1; k++){
                if(x[k] <= x[k+1]){
                    ok1 = false;
                    break;
                }
            }
            if(ok1){
                ok = true;
                break;
            }
        }
        cout << ok << '\n';
    }
    return 0;
}
