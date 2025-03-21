#include <iostream>
using namespace std;
int main(){
    int n, x;
    bool ok = true;
    cin >> n;
    for(int i =1; i <= n; i++){
        cin >> x;
        int f[10];
        for(int j = 0; j < 10; j++){
            f[j]= 0;
        }
        do{
            f[x%10]++;
            x = x/10;
        }while(x > 0);
        for(int j = 0; j < 10; j++){
            if(f[j] > 1){
                ok = false;
                break;
            }
        }
    }
    if(ok){
        cout << "DA";
    }else{
        cout << "NU";
    }
    return 0;
}
