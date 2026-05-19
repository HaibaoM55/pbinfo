#include <iostream>
using namespace std;
int inlocuire(int x){
    if(x == 0){
        return 0;
    }
    if(x % 2 == 0){
        return inlocuire(x/10)*10+x%10;
    }else{
        return inlocuire(x/10);
    }
}
int nrcif(int x){
    if(x < 10){
        return 1;
    }
    return 1+nrcif(x/10);
}
int n, x;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x;
        if(nrcif(x) % 2 != 0){
            cout << inlocuire(x) << ' ';
        }else{
            cout << x << ' ';
        }
    }
    return 0;
}
