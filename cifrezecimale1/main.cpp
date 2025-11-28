#include <iostream>
using namespace std;
int n, k;
int raspuns(int x){
    int c = (x-1)/3;
    int r = (x-1)%3;
    int nr = 100+c;
    if(r == 0){
        return nr/100;
    }else if(r == 1){
        return (nr/10)%10;
    }else{
        return nr%10;
    }
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> k;
        cout << raspuns(k) << ' ';
    }
    return 0;
}
